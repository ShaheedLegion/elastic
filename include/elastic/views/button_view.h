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

#ifndef ELASTIC_VIEWS_BUTTON_H_
#define ELASTIC_VIEWS_BUTTON_H_

#include <string>

#include "canvas/rendering/geometry.h"
#include "canvas/rendering/text.h"

#include "elastic/views/view.h"

namespace el {

class ButtonView : public View {
public:
  class OnClickListener {
  public:
    virtual ~OnClickListener();
    virtual void onButtonClicked(ButtonView* sender) = 0;
  };

  ButtonView(Context* context, const std::string& label = std::string{},
             OnClickListener* listener = nullptr);
  virtual ~ButtonView() override;

  // label
  const std::string& getLabel() const { return m_label; }
  void setLabel(const std::string& label);

  // Override: View
  virtual bool handlesInput() const { return true; }
  virtual bool onMousePressed(const ca::MouseEvent& event) override;
  virtual void onMouseReleased(const ca::MouseEvent& event) override;
  virtual void onMouseEntered(const ca::MouseEvent& event) override;
  virtual void onMouseExited(const ca::MouseEvent& event) override;
  virtual ca::Size<i32> calculateMinSize() const override;
  virtual void render(ca::Canvas* canvas,
                      const ca::Mat4& transform) const override;

private:
  // The label we print on the button.
  std::string m_label;

  // A listener that will receive events when the button is clicked.
  OnClickListener* m_listener;

  // The shape we use to render a background for the button.
  ca::Geometry m_backgroundShape;

  // The shape we use to render the label.
  ca::Text m_labelShape;

  DISALLOW_IMPLICIT_CONSTRUCTORS(ButtonView);
};

}  // namespace el

#endif  // ELASTIC_VIEWS_BUTTON_H_
