#ifndef UPLOADDIALOG_H
#define UPLOADDIALOG_H

#include <QDialog>
#include <QItemSelection>

namespace Ui {
    class HistoryDialog;
}

class QSortFilterProxyModel;
class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
  explicit HistoryDialog(QWidget *parent = 0);
  ~HistoryDialog();

private slots:
  void copy();
  void location();
  void contextMenu(QPoint point);
  void selectionChanged(QItemSelection selected, QItemSelection deselected);
  void open(QModelIndex index);
  void reloadHistory();
  void upload();
  void clear();

protected:
  bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::HistoryDialog *ui;
    QSortFilterProxyModel *mFilterModel;
    QString mSelectedScreenshot;
    QModelIndex mContextIndex;
};

#endif // UPLOADDIALOG_H