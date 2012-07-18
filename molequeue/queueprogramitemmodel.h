/******************************************************************************

  This source file is part of the MoleQueue project.

  Copyright 2012 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef QUEUEITEMMODEL_H
#define QUEUEITEMMODEL_H

#include <QtCore/QAbstractItemModel>

namespace MoleQueue
{
class Queue;

class QueueProgramItemModel : public QAbstractItemModel
{
  Q_OBJECT

  enum ColumnNames {
    PROGRAM_NAME = 0,

    COLUMN_COUNT // Use to get total number of columns
  };

public:
  explicit QueueProgramItemModel(Queue *queue, QObject *parentObject = 0);

  QModelIndex parent(const QModelIndex & modelIndex) const;
  int rowCount(const QModelIndex & modelIndex = QModelIndex()) const;
  int columnCount(const QModelIndex & modelIndex = QModelIndex()) const;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const;
  QVariant data(const QModelIndex & modelIndex,
                int role = Qt::DisplayRole) const;
  Qt::ItemFlags flags(const QModelIndex & modelIndex) const;

  bool removeRows(int row, int count, const QModelIndex &);

  QModelIndex index(int row, int column,
                    const QModelIndex & modelIndex = QModelIndex()) const;

protected slots:
  void callReset();

protected:
  Queue *m_queue;
};

} // End namespace

#endif