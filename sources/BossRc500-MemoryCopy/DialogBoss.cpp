#include "DialogBoss.hpp"
#include "BossReaderWriter.hpp"

#include <QFileDialog>
#include <QMessageBox>


// --------------------------------------------------------------------------
BossCopierDialog::BossCopierDialog(QDialog& dialog) :
        _parent(dialog)
{
    setup();
}

// --------------------------------------------------------------------------
void
BossCopierDialog::setup()
{
    setupUi(&_parent);

    // Add some tweaks...
    _parent.setFixedSize(_parent.width(), _parent.height());

    // Add MEMORY
    for (int i = 1; i <= 100; ++i) {
        cb_Memory->addItem(QString(std::to_string(i).c_str()));
        cb_CopyFrom->addItem(QString(std::to_string(i).c_str()));
        cb_CopyTo->addItem(QString(std::to_string(i).c_str()));
    }

    // Clear Filename
    label_Filename->setText(QString());

    QObject::connect(button_Open, &QPushButton::pressed, this, &BossCopierDialog::on_open);
    QObject::connect(button_Save, &QPushButton::pressed, this, &BossCopierDialog::on_save);
    QObject::connect(button_Quit, &QPushButton::pressed, this, &BossCopierDialog::on_quit);
}

// --------------------------------------------------------------------------
void
BossCopierDialog::on_open()
{
    auto filename = QFileDialog::getOpenFileName(&_parent,
            tr("Open a MEMORY file"), "", tr("Memory Files (*.RC0)"));

    label_Filename->setText(filename);
    if (!filename.isEmpty()) {
        try {
            _database = ReadMemoryDatabase(filename.toStdString());
        }
        catch (const std::exception& ex) {
            QMessageBox(QMessageBox::Warning, "", ex.what()).exec();
        }
    }
}

// --------------------------------------------------------------------------
void
BossCopierDialog::on_save()
{
    auto filename = label_Filename->text().toStdString();
    if (filename.empty()) {
        QMessageBox(QMessageBox::Warning, "", "No filename selected").exec();
        return;
    }

    // std::cout << "save file [" << filename << "]" << std::endl;
}

// --------------------------------------------------------------------------
void
BossCopierDialog::on_quit()
{
    QApplication::exit();
}
