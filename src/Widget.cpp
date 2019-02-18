/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 * @author Adeel Asghar <adeel.asghar@liu.se>
 */

#include "Widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QTreeWidget>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
}

Widget::~Widget()
{

}

QString Widget::name()
{
  return QString("OMSens");
}

QIcon Widget::icon()
{
  return QIcon(":/omedit.png");
}

void Widget::analyzeModel(const Model &model)
{
  QLabel *pNameLabel = new QLabel(model.mModelName);
  QLabel *pFilePathLabel = new QLabel(model.mFilePath);

  QTreeWidget *pTree = new QTreeWidget;
  pTree->setHeaderHidden(true);

  foreach (ComponentInformation componentInformation, model.mComponents) {
    QTreeWidgetItem *pItem = new QTreeWidgetItem(QStringList() << componentInformation.mName);

    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Classname : %1").arg(componentInformation.mClassName)));
    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Comment : %1").arg(componentInformation.mComment)));
    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Scope : %1").arg(componentInformation.mIsProtected ? "Protected" : "Public")));
    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Variability : %1").arg(componentInformation.mVariability)));
    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Casuality : %1").arg(componentInformation.mCasuality)));
    pItem->addChild(new QTreeWidgetItem(QStringList() << QString("Value : %1").arg(componentInformation.mParameterValue)));

    pTree->addTopLevelItem(pItem);
  }

  QVBoxLayout *pLayout = new QVBoxLayout;
  pLayout->addWidget(pNameLabel);
  pLayout->addWidget(pFilePathLabel);
  pLayout->addWidget(new QLabel("List of model components"));
  pLayout->addWidget(pTree);
  setLayout(pLayout);

  show();
}
