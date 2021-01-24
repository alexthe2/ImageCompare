#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->item_0_0->setScene(new QGraphicsScene());
    auto zoom = new Graphics_view_zoom(ui->item_0_0);
    zoom->set_modifiers(Qt::NoModifier);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetWindow() {
    int number = QInputDialog::getInt(ui->centralwidget, "Select numbers",
                                      "Select number of pictures to compare (square num)");
    number = static_cast<int>(sqrt(number));

    /* Now edit the grid layout and create the new window */
    this->removeAll();

    auto original = this->ui->item_0_0;
    loop(x, number) {
        loop(y, number) {
            if(x == 0 && y == 0) {
                this->elements.emplace(std::pair<int, int>(x, y), original);
                continue;
            }
            auto elem = new QGraphicsView(new QGraphicsScene(), original->parentWidget());
            auto zoom = new Graphics_view_zoom(elem);
            zoom->set_modifiers(Qt::NoModifier);
            zoomers.push_back(zoom);

            this->ui->mainLayout->addWidget(elem, y, x);
            this->elements.emplace(std::pair<int, int>(x, y), elem);
        }
    }
}

auto MainWindow::removeAll() -> void {
    for(auto elem : this->elements) {
        if (elem.first != std::pair<int, int>(0, 0)) {
            delete dynamic_cast<QGraphicsView*>(elem.second)->scene();
            this->ui->mainLayout->removeWidget(elem.second);
            delete elem.second;
        }
    }

    for(auto zoom : this->zoomers) {
        delete zoom;
    }

    this->zoomers.clear();
    this->elements.clear();
}

void MainWindow::LoadImages() {
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(trUtf8("Splits (*.png *.jpg)"));
    QStringList files;
    if (dialog.exec()) {
        files = dialog.selectedFiles();
        for(auto elem : this->elements) {
            auto widget = dynamic_cast<QGraphicsView*>(elem.second);
            if (files.isEmpty()) {
                break;
            }
            auto img = QImage(files.front());
            auto item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
            widget->scene()->addItem(item);
            widget->show();

            files.pop_front();
        }
    } else {
        QMessageBox messageBox;
        messageBox.critical(this,"Error","Please select files!");
        messageBox.setFixedSize(500,200);
        return;
    }
}

