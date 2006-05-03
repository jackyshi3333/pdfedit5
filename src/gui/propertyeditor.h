#ifndef __PROPERTYEDITOR_H__
#define __PROPERTYEDITOR_H__

#include <qobjectlist.h>
#include <qdict.h>
#include <qmap.h>
#include <qwidget.h>
#include <qgrid.h>
#include <qlayout.h>
#include <iproperty.h>

class QScrollView;
class QLabel;
class QStringList;

namespace gui {

class Property;

using namespace pdfobjects;

/** property editor widget */
class PropertyEditor : public QWidget {
 Q_OBJECT
public:
 PropertyEditor(QWidget *parent=0, const char *name=0);
 virtual ~PropertyEditor();
 void resizeEvent (QResizeEvent *e);
 void clear();
 void commitProperty();
public slots:
 void setObject(const QString &message);
 void setObject(boost::shared_ptr<IProperty> pdfObject);
 void setObject(const QString &name,boost::shared_ptr<IProperty> pdfObject);
 void update(Property *p);
signals:
 /** Signal emitted when any property is modified
  Send property pointer with the signal */
 void propertyChanged(IProperty *prop); 
private:
 bool addProperty(const QString &name,boost::shared_ptr<IProperty> value);
 void addProperty(Property *prop,boost::shared_ptr<IProperty> value);
 void deleteLayout();
 void createLayout();
private:
 /** Object currently edited */
 boost::shared_ptr<IProperty> obj;
 /** Number of objects in proiperty editor */
 int nObjects;
 /** Grid holding all property editing widgets*/
 QFrame *grid;
 /** Layout used for the grid */
 QGridLayout *gridl;
 /** Scrollview holding the grid */
 QScrollView *scroll;
 /** List of property names */
 QStringList *list;
 /** Dictionary with property items */
 QDict<Property> *items;
 /** Dictionary with IProperty items */
 QMap<QString,boost::shared_ptr<IProperty> > *props;
 /** Dictionary with property labels */
 QDict<QLabel> *labels;
};

} // namespace gui

#endif
