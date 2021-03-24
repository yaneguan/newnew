/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *plus;
    QPushButton *decr;
    QPushButton *multi;
    QPushButton *devison;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *N1;
    QPushButton *N2;
    QPushButton *N3;
    QHBoxLayout *horizontalLayout;
    QPushButton *N4;
    QPushButton *N5;
    QPushButton *N6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *N7;
    QPushButton *N8;
    QPushButton *N9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *N0;
    QPushButton *rest;
    QPushButton *clr;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(532, 414);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 30, 399, 251));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        plus = new QPushButton(widget);
        plus->setObjectName(QStringLiteral("plus"));

        horizontalLayout_5->addWidget(plus);

        decr = new QPushButton(widget);
        decr->setObjectName(QStringLiteral("decr"));

        horizontalLayout_5->addWidget(decr);

        multi = new QPushButton(widget);
        multi->setObjectName(QStringLiteral("multi"));

        horizontalLayout_5->addWidget(multi);

        devison = new QPushButton(widget);
        devison->setObjectName(QStringLiteral("devison"));

        horizontalLayout_5->addWidget(devison);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        N1 = new QPushButton(widget);
        N1->setObjectName(QStringLiteral("N1"));

        horizontalLayout_3->addWidget(N1);

        N2 = new QPushButton(widget);
        N2->setObjectName(QStringLiteral("N2"));

        horizontalLayout_3->addWidget(N2);

        N3 = new QPushButton(widget);
        N3->setObjectName(QStringLiteral("N3"));

        horizontalLayout_3->addWidget(N3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        N4 = new QPushButton(widget);
        N4->setObjectName(QStringLiteral("N4"));

        horizontalLayout->addWidget(N4);

        N5 = new QPushButton(widget);
        N5->setObjectName(QStringLiteral("N5"));

        horizontalLayout->addWidget(N5);

        N6 = new QPushButton(widget);
        N6->setObjectName(QStringLiteral("N6"));

        horizontalLayout->addWidget(N6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        N7 = new QPushButton(widget);
        N7->setObjectName(QStringLiteral("N7"));

        horizontalLayout_2->addWidget(N7);

        N8 = new QPushButton(widget);
        N8->setObjectName(QStringLiteral("N8"));

        horizontalLayout_2->addWidget(N8);

        N9 = new QPushButton(widget);
        N9->setObjectName(QStringLiteral("N9"));

        horizontalLayout_2->addWidget(N9);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        N0 = new QPushButton(widget);
        N0->setObjectName(QStringLiteral("N0"));

        horizontalLayout_4->addWidget(N0);

        rest = new QPushButton(widget);
        rest->setObjectName(QStringLiteral("rest"));

        horizontalLayout_4->addWidget(rest);

        clr = new QPushButton(widget);
        clr->setObjectName(QStringLiteral("clr"));

        horizontalLayout_4->addWidget(clr);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        plus->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        decr->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        multi->setText(QApplication::translate("Widget", "*", Q_NULLPTR));
        devison->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
        N1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        N2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        N3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        N4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        N5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        N6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        N7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        N8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        N9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        N0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        rest->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        clr->setText(QApplication::translate("Widget", "\346\270\205\351\233\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
