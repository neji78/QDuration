#include <QQmlExtensionPlugin>
#include <qqml.h>
#include "qduration.h"

class QtDurationPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override {
        // uri must match import name in QML
        qmlRegisterType<QDuration>(uri, 1, 0, "Duration");
    }
};
