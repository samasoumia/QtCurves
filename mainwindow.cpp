#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_ui()
{
        this->ui->spinScale->setValue(this->ui->renderArea->scale());
        this->ui->spinInterval->setValue(this->ui->renderArea->intervalLength());
        this->ui->spinCount->setValue(this->ui->renderArea->stepCount());
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
     this->ui->renderArea->setShape(RenderArea::Cycloid);
     this->ui->renderArea->repaint();
     update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
     this->ui->renderArea->setShape(RenderArea::HypoCycloid);
     this->ui->renderArea->repaint();
     update_ui();
}


void MainWindow::on_pushButton_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);

    update_ui();
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}



void MainWindow::on_spinInterval_valueChanged(double interval)
{
    this->ui->renderArea->setInterval(interval);
}

void MainWindow::on_spinCount_valueChanged(int count)
{
   this->ui->renderArea->setStepCount(count);

}

void MainWindow::on_btnBackground_clicked()
{
    //open a color picker dialog and change the button's color
    QColor color=QColorDialog::getColor(ui->renderArea->backgroundColor(),this,"Select Color");
    ui->renderArea->setBackgroundColor(color);
}

void MainWindow::on_btnLineColor_clicked()
{
    QColor color=QColorDialog::getColor(ui->renderArea->ShapeColor(),this,"Select Color");
    ui->renderArea->setShapeColor(color);
}
