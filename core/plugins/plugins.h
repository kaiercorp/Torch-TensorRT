#pragma once
#include <unordered_map>
#include "NvInferPlugin.h"
#include "NvInferPluginUtils.h"
#include "core/util/prelude.h"

#include <core_plugins_export.h>

namespace torch_tensorrt {
namespace core {
namespace plugins {
namespace impl {

CORE_PLUGINS_EXPORT int64_t dummy();

extern "C" CORE_PLUGINS_EXPORT auto _register_ops = &dummy;
#ifdef HINT_MSVC_LINKER_INCLUDE_SYMBOL
#pragma comment(linker, "/include:_register_ops")
#endif

// Helper class which registers a plugin in torch_tensorrt namespace
template <typename T>
class PluginRegistrar {
 public:
  PluginRegistrar() {
    getPluginRegistry()->registerCreator(instance, "torch_tensorrt");
  }

 private:
  T instance{};
};

#define REGISTER_TORCHTRT_PLUGIN(name) \
  static PluginRegistrar<name> pluginRegistrar##name {}

} // namespace impl
} // namespace plugins
} // namespace core
} // namespace torch_tensorrt
