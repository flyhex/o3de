/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#include "GemListView.h"
#include "GemItemDelegate.h"
#include <QStandardItemModel>
#include <QDateTime>
#include <QPalette>

namespace O3DE::ProjectManager
{
    GemListView::GemListView(GemModel* model, QWidget *parent) :
        QListView(parent)
    {
        setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        QPalette palette;
        palette.setColor(QPalette::Window, QColor("#333333"));
        setPalette(palette);

        setModel(model);
        setSelectionModel(model->GetSelectionModel());
        setItemDelegate(new GemItemDelegate(model, this));
    }
} // namespace O3DE::ProjectManager