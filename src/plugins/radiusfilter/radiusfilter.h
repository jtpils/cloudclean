#ifndef RADIUSFILTER_H
#define RADIUSFILTER_H

#include "pluginsystem/iplugin.h"
class QAction;
class QWidget;
class Core;
class CloudList;
class LayerList;
class FlatView;
class GLWidget;
class MainWindow;

class RadiusFilter : public IPlugin {
    Q_INTERFACES(IPlugin)
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "za.co.circlingthesun.cloudclean.radiusfilter" FILE "radiusfilter.json")
 public:
    QString getName();
    void initialize(Core * core);
    void cleanup();
    ~RadiusFilter();

 signals:
   void enabling();

 private slots:
    void enable();
    void disable();
    void filter();

 private:
    Core * core_;
    CloudList * cl_;
    LayerList * ll_;
    GLWidget * glwidget_;
    FlatView * flatview_;
    MainWindow * mw_;

    QAction * enable_;
    QWidget * settings_;
    bool is_enabled_;

    float radius_;
};

#endif  // RADIUSFILTER_H
