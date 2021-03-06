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

#ifndef ELASTIC_VIEWS_STACKED_SIZER_VIEW_H_
#define ELASTIC_VIEWS_STACKED_SIZER_VIEW_H_

#include "elastic/views/group_view.h"

namespace el {

class StackedSizerView : public GroupView {
public:
  explicit StackedSizerView(Context* context);
  virtual ~StackedSizerView();

  // Implement: GroupView
  virtual sf::Vector2i calculateMinSize() const override;
  virtual void layout(const sf::IntRect& rect) override;

private:
  DISALLOW_IMPLICIT_CONSTRUCTORS(StackedSizerView);
};

}  // namespace el

#endif  // ELASTIC_VIEWS_STACKED_SIZER_VIEW_H_
