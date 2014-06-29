#define Q_(a,b) QString::fromUtf8(_(a))
/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Sat Sep 21 17:34:26 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUT_H
#define ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *introduction;
    QLabel *infoLabel;
    QLabel *iconVLC;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *authorsEdit;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *thanksEdit;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *licenseEdit;
    QDialogButtonBox *closeButtonBox;

    void setupUi(QWidget *aboutWidget)
    {
        if (aboutWidget->objectName().isEmpty())
            aboutWidget->setObjectName(QString::fromUtf8("aboutWidget"));
        aboutWidget->resize(520, 357);
        gridLayout = new QGridLayout(aboutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(aboutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        introduction = new QLabel(tab);
        introduction->setObjectName(QString::fromUtf8("introduction"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(introduction->sizePolicy().hasHeightForWidth());
        introduction->setSizePolicy(sizePolicy);
        introduction->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        introduction->setFont(font);
        introduction->setText(QString::fromUtf8("introduction"));
        introduction->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(introduction, 0, 1, 1, 1);

        infoLabel = new QLabel(tab);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy1);
        infoLabel->setText(QString::fromUtf8("infoLabel"));
        infoLabel->setTextFormat(Qt::RichText);
        infoLabel->setWordWrap(true);
        infoLabel->setOpenExternalLinks(true);
        infoLabel->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        gridLayout_2->addWidget(infoLabel, 1, 1, 1, 1);

        iconVLC = new QLabel(tab);
        iconVLC->setObjectName(QString::fromUtf8("iconVLC"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(iconVLC->sizePolicy().hasHeightForWidth());
        iconVLC->setSizePolicy(sizePolicy2);
        iconVLC->setText(QString::fromUtf8("iconVLC"));

        gridLayout_2->addWidget(iconVLC, 0, 0, 2, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        authorsEdit = new QTextEdit(tab_2);
        authorsEdit->setObjectName(QString::fromUtf8("authorsEdit"));
        authorsEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(authorsEdit);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        thanksEdit = new QTextEdit(tab_3);
        thanksEdit->setObjectName(QString::fromUtf8("thanksEdit"));
        thanksEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(thanksEdit);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        licenseEdit = new QTextEdit(tab_4);
        licenseEdit->setObjectName(QString::fromUtf8("licenseEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier"));
        licenseEdit->setFont(font1);
        licenseEdit->setLineWrapMode(QTextEdit::NoWrap);
        licenseEdit->setAcceptRichText(false);
        licenseEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(licenseEdit);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        closeButtonBox = new QDialogButtonBox(aboutWidget);
        closeButtonBox->setObjectName(QString::fromUtf8("closeButtonBox"));
        closeButtonBox->setStandardButtons(QDialogButtonBox::NoButton);

        gridLayout->addWidget(closeButtonBox, 1, 0, 1, 1);


        retranslateUi(aboutWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(aboutWidget);
    } // setupUi

    void retranslateUi(QWidget *aboutWidget)
    {
        aboutWidget->setWindowTitle(Q_("About", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), Q_("Version", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), Q_("Authors", 0));
        label->setText(Q_("We would like to thank the whole VLC community, the testers, our users and the following people (and the missing ones...) for their collaboration to create the best free software.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), Q_("Thanks", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), Q_("Licence", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutWidget: public Ui_aboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUT_H
