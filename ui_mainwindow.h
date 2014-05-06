/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *lblImage1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblImage1path;
    QSpacerItem *horizontalSpacer;
    QPushButton *bttLoadImage1;
    QLabel *lblImage2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblImage2path;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bttnLoadImage2;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QSlider *horizontalSlider;
    QLabel *label_6;
    QLabel *lblthresholdVal;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *bttnCompare;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(942, 651);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblImage1 = new QLabel(frame);
        lblImage1->setObjectName(QString::fromUtf8("lblImage1"));
        lblImage1->setMinimumSize(QSize(458, 380));
        lblImage1->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border: 1px solid #000;"));

        gridLayout_2->addWidget(lblImage1, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lblImage1path = new QLabel(frame);
        lblImage1path->setObjectName(QString::fromUtf8("lblImage1path"));

        horizontalLayout->addWidget(lblImage1path);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bttLoadImage1 = new QPushButton(frame);
        bttLoadImage1->setObjectName(QString::fromUtf8("bttLoadImage1"));
        bttLoadImage1->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(bttLoadImage1);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        lblImage2 = new QLabel(frame);
        lblImage2->setObjectName(QString::fromUtf8("lblImage2"));
        lblImage2->setMinimumSize(QSize(458, 380));
        lblImage2->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border: 1px solid #000;"));

        gridLayout_2->addWidget(lblImage2, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lblImage2path = new QLabel(frame);
        lblImage2path->setObjectName(QString::fromUtf8("lblImage2path"));

        horizontalLayout_2->addWidget(lblImage2path);

        horizontalSpacer_2 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        bttnLoadImage2 = new QPushButton(frame);
        bttnLoadImage2->setObjectName(QString::fromUtf8("bttnLoadImage2"));
        bttnLoadImage2->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(bttnLoadImage2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 4);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(150, 0));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(7, 28, 71, 21));

        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(225, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(220, 0));
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 50, 191, 23));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 30, 52, 13));
        lblthresholdVal = new QLabel(groupBox_3);
        lblthresholdVal->setObjectName(QString::fromUtf8("lblthresholdVal"));
        lblthresholdVal->setGeometry(QRect(90, 30, 52, 13));

        gridLayout_3->addWidget(groupBox_3, 1, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        bttnCompare = new QPushButton(centralWidget);
        bttnCompare->setObjectName(QString::fromUtf8("bttnCompare"));
        bttnCompare->setMinimumSize(QSize(200, 38));

        gridLayout->addWidget(bttnCompare, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 942, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Color Matching", 0, QApplication::UnicodeUTF8));
        lblImage1->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Imagen 1:", 0, QApplication::UnicodeUTF8));
        lblImage1path->setText(QString());
        bttLoadImage1->setText(QApplication::translate("MainWindow", "Cargar Imagen", 0, QApplication::UnicodeUTF8));
        lblImage2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Imagen 2", 0, QApplication::UnicodeUTF8));
        lblImage2path->setText(QString());
        bttnLoadImage2->setText(QApplication::translate("MainWindow", "Cargar Imagen", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Preprocesamiento", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Ninguno", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Procesamiento", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "comparaci\303\263n con histogramas \n"
"  en HSV", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "comparaci\303\263n con histogramas \n"
" en RGB", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MainWindow", "comparaci\303\263n en   espacio \n"
" de color CIEL*a*b* ", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Par\303\241metros", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Umbral   :", 0, QApplication::UnicodeUTF8));
        lblthresholdVal->setText(QApplication::translate("MainWindow", "num", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        bttnCompare->setText(QApplication::translate("MainWindow", "Comparar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
