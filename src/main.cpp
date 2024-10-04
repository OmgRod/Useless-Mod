#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        static bool inited = false;
        if (!inited) {
            inited = true;

            queueInMainThread([this]() {
                FLAlertLayer::create("Useless Mod", "This mod has been uninstalled", "OK");
                Mod::get()->uninstall();
            });
        }

        return true;
    }
};