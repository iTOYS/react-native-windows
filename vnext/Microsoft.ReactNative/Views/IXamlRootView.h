// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <IReactRootView.h>
#include <React.h>
#include <folly/dynamic.h>
#include "XamlView.h"

namespace Microsoft::ReactNative {

struct IXamlReactControl {
  virtual void blur(Microsoft::ReactNative::XamlView const &xamlView) noexcept = 0;
};

struct IXamlRootView : public facebook::react::IReactRootView {
  virtual Mso::React::IReactContext *GetReactContext() const noexcept = 0;
  virtual Microsoft::ReactNative::XamlView GetXamlView() const noexcept = 0;

  virtual void SetJSComponentName(std::string &&mainComponentName) noexcept = 0;
  virtual void SetInitialProps(folly::dynamic &&initialProps) noexcept = 0;

  virtual void AttachRoot() noexcept = 0;
  virtual void DetachRoot() noexcept = 0;

  virtual std::shared_ptr<IXamlReactControl> GetXamlReactControl() const noexcept = 0;
};

} // namespace Microsoft::ReactNative
