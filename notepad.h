#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notepad; }
QT_END_NAMESPACE

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionSave_AS_triggered();

    void on_actioncut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionabout_notepad_triggered();

private:
    Ui::notepad *ui;
    QString file_path_;
};
#endif // NOTEPAD_H
