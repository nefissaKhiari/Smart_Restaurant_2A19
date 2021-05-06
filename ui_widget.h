/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *Menu;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *Title;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QPushButton *StartBtn;
    QPushButton *HTPbtn;
    QPushButton *ExitBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QWidget *selectpic;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backfromselectpic;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *nexttogame;
    QWidget *gameplay;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QDockWidget *puzzle_dock_widget;
    QWidget *dockWidgetContents_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *solution_pic;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpinBox *size_spinBox;
    QSpacerItem *verticalSpacer_3;
    QPushButton *scramble_pushButton;
    QPushButton *reset_pushButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(900, 625);
        Widget->setMinimumSize(QSize(900, 625));
        Widget->setBaseSize(QSize(850, 625));
        QPalette palette;
        QBrush brush(QColor(230, 230, 230, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(252, 252, 252, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QLinearGradient gradient(0.05, 0.04, 1, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 0, 255, 255));
        gradient.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush2(gradient);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QLinearGradient gradient1(0.05, 0.04, 1, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 0, 255, 255));
        gradient1.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush3(gradient1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        QLinearGradient gradient2(0.05, 0.04, 1, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 0, 255, 255));
        gradient2.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush5(gradient2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        Widget->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Images/Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setBaseSize(QSize(0, 0));
        stackedWidget->setAutoFillBackground(true);
        Menu = new QWidget();
        Menu->setObjectName(QStringLiteral("Menu"));
        verticalLayout_2 = new QVBoxLayout(Menu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 60, -1, -1);
        Title = new QLabel(Menu);
        Title->setObjectName(QStringLiteral("Title"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        Title->setPalette(palette1);
        Title->setScaledContents(false);
        Title->setAlignment(Qt::AlignCenter);
        Title->setWordWrap(false);
        Title->setOpenExternalLinks(false);

        verticalLayout_6->addWidget(Title);


        verticalLayout_2->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(40);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(15, 0, 0, 30);
        StartBtn = new QPushButton(Menu);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartBtn->sizePolicy().hasHeightForWidth());
        StartBtn->setSizePolicy(sizePolicy);
        StartBtn->setMinimumSize(QSize(300, 50));
        StartBtn->setMaximumSize(QSize(200, 16777215));
        QPalette palette2;
        QBrush brush6(QColor(218, 218, 218, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient3(0.05, 0.04, 1, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 0, 255, 255));
        gradient3.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush7(gradient3);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(255, 255, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient4(0.05, 0.04, 1, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 0, 255, 255));
        gradient4.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush9(gradient4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush9);
        QLinearGradient gradient5(0.05, 0.04, 1, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 0, 255, 255));
        gradient5.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush10(gradient5);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush10);
        QBrush brush11(QColor(218, 218, 218, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient6(0.05, 0.04, 1, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 0, 255, 255));
        gradient6.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush12(gradient6);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient7(0.05, 0.04, 1, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 0, 255, 255));
        gradient7.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush13(gradient7);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        QLinearGradient gradient8(0.05, 0.04, 1, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 0, 255, 255));
        gradient8.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush14(gradient8);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush14);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        QLinearGradient gradient9(0.05, 0.04, 1, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(0, 0, 255, 255));
        gradient9.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush15(gradient9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        QLinearGradient gradient10(0.05, 0.04, 1, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(0, 0, 255, 255));
        gradient10.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush16(gradient10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        QLinearGradient gradient11(0.05, 0.04, 1, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(0, 0, 255, 255));
        gradient11.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush17(gradient11);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush17);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        StartBtn->setPalette(palette2);
        QFont font;
        font.setFamily(QStringLiteral("Tekton Pro Ext"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        StartBtn->setFont(font);
        StartBtn->setCursor(QCursor(Qt::PointingHandCursor));
        StartBtn->setMouseTracking(true);
        StartBtn->setContextMenuPolicy(Qt::DefaultContextMenu);
        StartBtn->setAcceptDrops(false);
        StartBtn->setAutoFillBackground(false);
        StartBtn->setStyleSheet(QStringLiteral("border:  solid transparent;"));
        StartBtn->setInputMethodHints(Qt::ImhNone);
        StartBtn->setFlat(true);

        verticalLayout_5->addWidget(StartBtn);

        HTPbtn = new QPushButton(Menu);
        HTPbtn->setObjectName(QStringLiteral("HTPbtn"));
        sizePolicy.setHeightForWidth(HTPbtn->sizePolicy().hasHeightForWidth());
        HTPbtn->setSizePolicy(sizePolicy);
        HTPbtn->setMinimumSize(QSize(300, 50));
        HTPbtn->setMaximumSize(QSize(160, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        HTPbtn->setPalette(palette3);
        HTPbtn->setFont(font);
        HTPbtn->setCursor(QCursor(Qt::PointingHandCursor));
        HTPbtn->setMouseTracking(true);
        HTPbtn->setStyleSheet(QStringLiteral("border: solid transparent;"));
        HTPbtn->setFlat(true);

        verticalLayout_5->addWidget(HTPbtn);

        ExitBtn = new QPushButton(Menu);
        ExitBtn->setObjectName(QStringLiteral("ExitBtn"));
        ExitBtn->setMinimumSize(QSize(135, 50));
        ExitBtn->setMaximumSize(QSize(110, 50));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        ExitBtn->setPalette(palette4);
        QFont font1;
        font1.setFamily(QStringLiteral("Tekton Pro Ext"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setKerning(true);
        ExitBtn->setFont(font1);
        ExitBtn->setCursor(QCursor(Qt::PointingHandCursor));
        ExitBtn->setMouseTracking(true);
        ExitBtn->setAcceptDrops(false);
        ExitBtn->setAutoFillBackground(false);
        ExitBtn->setStyleSheet(QStringLiteral("border: solid transparent;"));
        ExitBtn->setFlat(true);

        verticalLayout_5->addWidget(ExitBtn);


        verticalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, 5, 15, 15);
        label_3 = new QLabel(Menu);
        label_3->setObjectName(QStringLiteral("label_3"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush8);
        QLinearGradient gradient12(0.05, 0.04, 1, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(0, 0, 255, 255));
        gradient12.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush18(gradient12);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush18);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        QLinearGradient gradient13(0.05, 0.04, 1, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(0, 0, 255, 255));
        gradient13.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush19(gradient13);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush19);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        QLinearGradient gradient14(0.05, 0.04, 1, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(0, 0, 255, 255));
        gradient14.setColorAt(1, QColor(0, 0, 64, 255));
        QBrush brush20(gradient14);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush20);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_3->setPalette(palette5);
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setFrameShape(QFrame::Box);
        label_3->setScaledContents(false);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(Menu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_2->setPalette(palette6);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(Menu);
        selectpic = new QWidget();
        selectpic->setObjectName(QStringLiteral("selectpic"));
        verticalLayout_4 = new QVBoxLayout(selectpic);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_6 = new QLabel(selectpic);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 80));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_6->setPalette(palette7);
        QFont font3;
        font3.setFamily(QStringLiteral("Stylus BT"));
        font3.setPointSize(37);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 10, 10, 10);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        comboBox = new QComboBox(selectpic);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/awesome3x3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/troll_face3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/rage3x3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/classic4x4.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/gray4x4.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/red4x4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/orange4x4.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Images/rupp3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Images/ited3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Images/tb3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Images/me3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon11, QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(400, 50));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush21(QColor(0, 0, 0, 128));
        brush21.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush21);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        comboBox->setPalette(palette8);
        QFont font4;
        font4.setFamily(QStringLiteral("Stylus BT"));
        font4.setPointSize(15);
        comboBox->setFont(font4);
        comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox->setMouseTracking(true);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setMaxVisibleItems(7);
        comboBox->setIconSize(QSize(40, 40));
        comboBox->setFrame(true);

        horizontalLayout_5->addWidget(comboBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(10, 10, 10, 10);
        label_4 = new QLabel(selectpic);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_4->setPalette(palette9);
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setUnderline(true);
        font5.setWeight(75);
        label_4->setFont(font5);

        verticalLayout_7->addWidget(label_4);

        label_7 = new QLabel(selectpic);
        label_7->setObjectName(QStringLiteral("label_7"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_7->setPalette(palette10);
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        label_7->setFont(font6);

        verticalLayout_7->addWidget(label_7);

        label_8 = new QLabel(selectpic);
        label_8->setObjectName(QStringLiteral("label_8"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_8->setPalette(palette11);
        label_8->setFont(font6);

        verticalLayout_7->addWidget(label_8);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        backfromselectpic = new QPushButton(selectpic);
        backfromselectpic->setObjectName(QStringLiteral("backfromselectpic"));
        backfromselectpic->setMinimumSize(QSize(115, 60));
        backfromselectpic->setMaximumSize(QSize(115, 60));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        backfromselectpic->setPalette(palette12);
        QFont font7;
        font7.setFamily(QStringLiteral("Stylus BT"));
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setWeight(75);
        backfromselectpic->setFont(font7);
        backfromselectpic->setCursor(QCursor(Qt::PointingHandCursor));
        backfromselectpic->setMouseTracking(true);
        backfromselectpic->setStyleSheet(QStringLiteral("border: solid transparent;"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Images/Back button white.png"), QSize(), QIcon::Normal, QIcon::Off);
        backfromselectpic->setIcon(icon12);
        backfromselectpic->setIconSize(QSize(35, 45));
        backfromselectpic->setFlat(true);

        horizontalLayout_4->addWidget(backfromselectpic);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        nexttogame = new QPushButton(selectpic);
        nexttogame->setObjectName(QStringLiteral("nexttogame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nexttogame->sizePolicy().hasHeightForWidth());
        nexttogame->setSizePolicy(sizePolicy1);
        nexttogame->setMinimumSize(QSize(100, 60));
        nexttogame->setMaximumSize(QSize(100, 60));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        nexttogame->setPalette(palette13);
        nexttogame->setFont(font7);
        nexttogame->setCursor(QCursor(Qt::PointingHandCursor));
        nexttogame->setMouseTracking(true);
        nexttogame->setLayoutDirection(Qt::RightToLeft);
        nexttogame->setAutoFillBackground(false);
        nexttogame->setStyleSheet(QStringLiteral("border: solid transparent;"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Images/Next button white.png"), QSize(), QIcon::Normal, QIcon::Off);
        nexttogame->setIcon(icon13);
        nexttogame->setIconSize(QSize(35, 45));
        nexttogame->setFlat(true);

        horizontalLayout_4->addWidget(nexttogame);


        verticalLayout_4->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(selectpic);
        gameplay = new QWidget();
        gameplay->setObjectName(QStringLiteral("gameplay"));
        verticalLayout_8 = new QVBoxLayout(gameplay);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        puzzle_dock_widget = new QDockWidget(gameplay);
        puzzle_dock_widget->setObjectName(QStringLiteral("puzzle_dock_widget"));
        puzzle_dock_widget->setMinimumSize(QSize(300, 300));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        puzzle_dock_widget->setPalette(palette14);
        QFont font8;
        font8.setFamily(QStringLiteral("Stylus BT"));
        font8.setPointSize(17);
        font8.setBold(true);
        font8.setWeight(75);
        puzzle_dock_widget->setFont(font8);
        puzzle_dock_widget->setCursor(QCursor(Qt::PointingHandCursor));
        puzzle_dock_widget->setMouseTracking(true);
        puzzle_dock_widget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        puzzle_dock_widget->setWidget(dockWidgetContents_4);

        horizontalLayout_3->addWidget(puzzle_dock_widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(13);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(gameplay);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label_5->setPalette(palette15);
        QFont font9;
        font9.setFamily(QStringLiteral("Stylus BT"));
        font9.setPointSize(17);
        font9.setBold(true);
        font9.setUnderline(true);
        font9.setWeight(75);
        label_5->setFont(font9);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        solution_pic = new QLabel(gameplay);
        solution_pic->setObjectName(QStringLiteral("solution_pic"));
        solution_pic->setMinimumSize(QSize(250, 250));
        solution_pic->setMaximumSize(QSize(250, 250));
        solution_pic->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(solution_pic);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label = new QLabel(gameplay);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label->setPalette(palette16);
        QFont font10;
        font10.setFamily(QStringLiteral("Stylus BT"));
        font10.setPointSize(15);
        font10.setBold(false);
        font10.setUnderline(false);
        font10.setWeight(50);
        label->setFont(font10);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label);

        size_spinBox = new QSpinBox(gameplay);
        size_spinBox->setObjectName(QStringLiteral("size_spinBox"));
        size_spinBox->setMinimumSize(QSize(0, 30));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        size_spinBox->setPalette(palette17);
        QFont font11;
        font11.setPointSize(12);
        size_spinBox->setFont(font11);
        size_spinBox->setCursor(QCursor(Qt::PointingHandCursor));
        size_spinBox->setMouseTracking(true);
        size_spinBox->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        size_spinBox->setMinimum(3);
        size_spinBox->setMaximum(5);

        verticalLayout_3->addWidget(size_spinBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        scramble_pushButton = new QPushButton(gameplay);
        scramble_pushButton->setObjectName(QStringLiteral("scramble_pushButton"));
        scramble_pushButton->setMinimumSize(QSize(0, 30));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        scramble_pushButton->setPalette(palette18);
        QFont font12;
        font12.setFamily(QStringLiteral("Stylus BT"));
        font12.setPointSize(15);
        font12.setBold(true);
        font12.setWeight(75);
        scramble_pushButton->setFont(font12);
        scramble_pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        scramble_pushButton->setMouseTracking(true);
        scramble_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        scramble_pushButton->setCheckable(false);
        scramble_pushButton->setAutoDefault(false);
        scramble_pushButton->setFlat(false);

        verticalLayout_3->addWidget(scramble_pushButton);

        reset_pushButton = new QPushButton(gameplay);
        reset_pushButton->setObjectName(QStringLiteral("reset_pushButton"));
        reset_pushButton->setMinimumSize(QSize(0, 30));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette19.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette19.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette19.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        reset_pushButton->setPalette(palette19);
        reset_pushButton->setFont(font12);
        reset_pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        reset_pushButton->setMouseTracking(true);
        reset_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(reset_pushButton);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        back = new QPushButton(gameplay);
        back->setObjectName(QStringLiteral("back"));
        back->setMinimumSize(QSize(115, 60));
        back->setMaximumSize(QSize(115, 60));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette20.setBrush(QPalette::Active, QPalette::Dark, brush8);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        back->setPalette(palette20);
        back->setFont(font7);
        back->setCursor(QCursor(Qt::PointingHandCursor));
        back->setMouseTracking(true);
        back->setStyleSheet(QStringLiteral("border: solid transparent;"));
        back->setIcon(icon12);
        back->setIconSize(QSize(35, 45));
        back->setFlat(true);

        horizontalLayout_7->addWidget(back);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        verticalLayout_8->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(gameplay);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);
        comboBox->setCurrentIndex(0);
        scramble_pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        Title->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        StartBtn->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        StartBtn->setText(QApplication::translate("Widget", "Start game", Q_NULLPTR));
        HTPbtn->setText(QApplication::translate("Widget", "How to play", Q_NULLPTR));
        ExitBtn->setText(QApplication::translate("Widget", "Exit", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "Made by Three Brothers. All rights reserved.", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Version 1.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "Select picture", Q_NULLPTR));
        comboBox->setItemText(0, QApplication::translate("Widget", "Smiley Emoji", Q_NULLPTR));
        comboBox->setItemText(1, QApplication::translate("Widget", "Troll Face", Q_NULLPTR));
        comboBox->setItemText(2, QApplication::translate("Widget", "FFFFFUUUUUU", Q_NULLPTR));
        comboBox->setItemText(3, QApplication::translate("Widget", "Classic Board", Q_NULLPTR));
        comboBox->setItemText(4, QApplication::translate("Widget", "Classic Gray Board", Q_NULLPTR));
        comboBox->setItemText(5, QApplication::translate("Widget", "Red Board", Q_NULLPTR));
        comboBox->setItemText(6, QApplication::translate("Widget", "Orange Board", Q_NULLPTR));
        comboBox->setItemText(7, QApplication::translate("Widget", "RUPP logo", Q_NULLPTR));
        comboBox->setItemText(8, QApplication::translate("Widget", "ITED logo", Q_NULLPTR));
        comboBox->setItemText(9, QApplication::translate("Widget", "ThreeBrothers logo", Q_NULLPTR));
        comboBox->setItemText(10, QApplication::translate("Widget", "ME", Q_NULLPTR));

        label_4->setText(QApplication::translate("Widget", "Tip:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "Fifteen-numbers puzzle only", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "available in 4x4 level.", Q_NULLPTR));
        backfromselectpic->setText(QApplication::translate("Widget", "Menu", Q_NULLPTR));
        nexttogame->setText(QApplication::translate("Widget", "Next", Q_NULLPTR));
        puzzle_dock_widget->setWindowTitle(QApplication::translate("Widget", "Puzzle Board", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "Solution", Q_NULLPTR));
        solution_pic->setText(QString());
        label->setText(QApplication::translate("Widget", "Select level:", Q_NULLPTR));
        scramble_pushButton->setText(QApplication::translate("Widget", "Scramble", Q_NULLPTR));
        reset_pushButton->setText(QApplication::translate("Widget", "Reset", Q_NULLPTR));
        back->setText(QApplication::translate("Widget", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
