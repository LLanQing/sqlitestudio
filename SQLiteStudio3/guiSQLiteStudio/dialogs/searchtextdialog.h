#ifndef SEARCHTEXTDIALOG_H
#define SEARCHTEXTDIALOG_H

#include "guiSQLiteStudio_global.h"
#include <QDialog>

namespace Ui {
    class SearchTextDialog;
}

class SearchTextLocator;

class GUI_API_EXPORT SearchTextDialog : public QDialog
{
        Q_OBJECT

    public:
        explicit SearchTextDialog(SearchTextLocator* textLocator, QWidget *parent = 0);
        ~SearchTextDialog();

    protected:
        void changeEvent(QEvent *e);
        void showEvent(QShowEvent* e);

    private:
        void applyConfigToLocator();

        Ui::SearchTextDialog *ui = nullptr;
        SearchTextLocator* textLocator = nullptr;
        bool configModifiedState = false;

    private slots:
        void setReplaceAvailable(bool available);
        void on_findButton_clicked();
        void on_replaceButton_clicked();
        void on_replaceAllButton_clicked();
        void markModifiedState();
};

#endif // SEARCHTEXTDIALOG_H
