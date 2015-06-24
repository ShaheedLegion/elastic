// Copyright (c) 2015, Tiaan Louw
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#include "elastic/views/linear_sizer_view.h"

#include <cmath>
#include <algorithm>

namespace el {

LinearSizerView::LinearSizerView(Context* context)
  : GroupView(context), m_orientation(OrientationHorizontal) {
}

LinearSizerView::LinearSizerView(Context* context, OrientationType orientation)
  : GroupView(context), m_orientation(orientation) {
}

LinearSizerView::~LinearSizerView() {
}

void LinearSizerView::SetOrientation(OrientationType orientation) {
  m_orientation = orientation;
}

ca::Size<i32> LinearSizerView::calculateMinSize() const {
  ca::Size<i32> minSize{GroupView::calculateMinSize()};
   
  ca::Size<i32> contentSize;
  if (m_orientation == OrientationHorizontal) {
    for (const auto& child : m_children) {
      ca::Size<i32> childMinSize{child->calculateMinSize()};
      contentSize.width += childMinSize.width;
      contentSize.height = std::max(contentSize.height, childMinSize.height);
    }
  } else {
    for (const auto& child : m_children) {
      ca::Size<i32> childMinSize{child->calculateMinSize()};
      contentSize.width = std::max(contentSize.width, childMinSize.width);
      contentSize.height += childMinSize.height;
    }
  }

  minSize.width = std::max(minSize.width, contentSize.width);
  minSize.height = std::max(minSize.height, contentSize.height);

  return minSize;
}

void LinearSizerView::layout(const ca::Rect<i32>& rect) {
  GroupView::layout(rect);

  if (m_orientation == OrientationHorizontal)
    layoutHorizontal(rect);
  else
    layoutVertical(rect);
}

void LinearSizerView::layoutHorizontal(const ca::Rect<i32>& rect) {
  // Make place where we can store the size for each child.
  std::vector<std::pair<i32, ca::Size<i32>>> sizes;
  sizes.resize(m_children.size(), std::make_pair(0, ca::Size<i32>{}));

  // The total width available to us.
  int32_t totalSize = rect.size.width;
  int32_t totalProportion = 0;
  for (size_t i = 0; i < m_children.size(); ++i) {
    sizes[i].first = m_children[i]->getProportion();
    sizes[i].second = m_children[i]->calculateMinSize();

    // Calculate the total number of proportions we need.
    totalProportion += m_children[i]->getProportion();

    // Adjust the space we have to divide between the views.
    totalSize -= sizes[i].second.width;
  }

  // Calculate the size we have per proportion for each view.
  float singleProportionSize =
      (totalProportion > 0)
          ? static_cast<float>(totalSize) / static_cast<float>(totalProportion)
          : 0.f;

  // Start with the entire area we have available.
  ca::Rect<i32> sectionRect{rect};
  for (size_t i = 0; i < m_children.size(); ++i) {
    // The height available is the minSize of the view + the amount we receive
    // from the total left over space.
    sectionRect.size.width =
        sizes[i].second.width +
        std::lround(singleProportionSize *
                    static_cast<float>(m_children[i]->getProportion()));

    // Layout the child view.
    m_children[i]->layout(layoutControlInRect(m_children[i], sectionRect));

    // Adjust the top of the layout rect to where the next view will be layed
    // out.
    sectionRect.pos.x += sectionRect.size.width;
  }
}

void LinearSizerView::layoutVertical(const ca::Rect<i32>& rect) {
  // Make place where we can store the size for each child.
  std::vector<std::pair<int32_t, ca::Size<i32>>> sizes;
  sizes.resize(m_children.size(), std::make_pair(0, ca::Size<i32>{}));

  // The total height available to us.
  int32_t totalSize = rect.size.height;
  int32_t totalProportion = 0;
  for (size_t i = 0; i < m_children.size(); ++i) {
    sizes[i].first = m_children[i]->getProportion();
    sizes[i].second = m_children[i]->calculateMinSize();

    // Calculate the total number of proportions we need.
    totalProportion += m_children[i]->getProportion();

    // Adjust the space we have to divide between the views.
    totalSize -= sizes[i].second.height;
  }

  // Calculate the size we have per proportion for each view.
  float singleProportionSize =
      (totalProportion > 0)
          ? static_cast<float>(totalSize) / static_cast<float>(totalProportion)
          : 0.f;

  // Start with the entire area we have available.
  ca::Rect<i32> sectionRect{rect};
  for (size_t i = 0; i < m_children.size(); ++i) {
    // The height available is the minSize of the view + the amount we receive
    // from the total left over space.
    sectionRect.size.height =
        sizes[i].second.height +
        std::lround(singleProportionSize *
                    static_cast<float>(m_children[i]->getProportion()));

    // Layout the child view.
    m_children[i]->layout(layoutControlInRect(m_children[i], sectionRect));

    // Adjust the top of the layout rect to where the next view will be layed
    // out.
    sectionRect.pos.y += sectionRect.size.height;
  }
}

}  // namespace el
