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

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include "../../OMEdit/OMEdit/OMEditGUI/Interfaces/InformationInterface.h"
#include "../../OMEdit/OMEdit/OMEditGUI/Interfaces/ModelInterface.h"

class Widget : public QWidget, public InformationInterface, public ModelInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.openmodelica.OMEdit.plugins.OMSensPlugin")
  Q_INTERFACES(InformationInterface ModelInterface)

public:
  Widget(QWidget *parent = 0);
  ~Widget();

  // InformationInterface interface
public:
  QString name() override;
  QIcon icon() override;

  // ModelInterface interface
public:
  void analyzeModel(const Model &model) override;
};

#endif // WIDGET_H
