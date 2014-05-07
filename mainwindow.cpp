#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sliderThreshold->setValue(0);
    ui->lblthresholdVal->setText(QString("%1").arg(ui->sliderThreshold->value()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bttLoadImage1_clicked()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open Image Files"),
                                "",
                                tr("Image files (*.jpg *.jpeg *.png *.gif *.bmp)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty()){
        cv::Mat img_mat = cv::imread(fileName.toStdString(),1); //0 for grayscale
        displayMat(img_mat,1);
    }
    //Set Filename
    ColorDetectController::getInstance()->setPatternImage(fileName.toStdString());



}

void MainWindow::on_bttnLoadImage2_clicked()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open Image Files"),
                                "",
                                tr("Image files (*.jpg *.jpeg *.png *.gif *.bmp)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty()){
        cv::Mat img_mat = cv::imread(fileName.toStdString(),2); //0 for grayscale
        displayMat(img_mat,2);
    }
    //Set Filename
    ColorDetectController::getInstance()->setTargetImage(fileName.toStdString());

}

void MainWindow::on_bttnCompare_clicked()
{

    ColorDetectController::getInstance()->setColorDistanceThreshold(ui->sliderThreshold->value());
    ColorDetectController::getInstance()->process();

    cv::Mat resulting = ColorDetectController::getInstance()->getLastResult();
    if (!resulting.empty())
        displayMat(resulting,2);



}

void MainWindow::displayMat(const Mat &image,int numImage)
{
    //BGR openCV Mat to QImage
    QImage img_qt = QImage((const unsigned char*)image.data,image.cols, image.rows, image.step, QImage::Format_RGB888);

    //For Binary Images
    if (img_qt.isNull()){
        //ColorTable for Binary Images
        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++)
            colorTable.push_back(qRgb(i, i, i));

        img_qt = QImage((const unsigned char*)image.data,image.cols, image.rows, QImage::Format_Indexed8);
        img_qt.setColorTable(colorTable);
        }

    //Display the QImage in the Label
    QPixmap img_pix = QPixmap::fromImage(img_qt.rgbSwapped()); //BGR to RGB

    switch (numImage) {
        case 1:
            this->ui->lblImage1->setPixmap(img_pix.scaled(ui->lblImage1->size(), Qt::KeepAspectRatio));
        break;
        case 2:
            this->ui->lblImage2->setPixmap(img_pix.scaled(ui->lblImage2->size(), Qt::KeepAspectRatio));
        default:
            break;
    }

}

QImage MainWindow::Mat2QImage(const Mat &src)
{
    cv::Mat temp; // make the same cv::Mat
    cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage dest((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    QImage dest2(dest);
    dest2.detach(); // enforce deep copy
    return dest2;
}

Mat MainWindow::QImage2Mat(const QImage &src)
{
    cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
    cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
    cvtColor(tmp, result,CV_BGR2RGB);
    return result;
}

QString MainWindow::getFileName(QString path)
{
    int indexlastof = path.lastIndexOf("/");
    return path.left(indexlastof);

}


void MainWindow::on_sliderThreshold_valueChanged(int value)
{
    ui->lblthresholdVal->setText(QString("%1").arg(value));

    ColorDetectController::getInstance()->setColorDistanceThreshold(ui->sliderThreshold->value());
    ColorDetectController::getInstance()->process();
    float difference = ColorDetectController::getInstance()->getDifference();

    cv::Mat resulting = ColorDetectController::getInstance()->getLastResult();
    if (!resulting.empty())
        displayMat(resulting,2);

    this->ui->lblDiference->setText(QString("%1").arg(difference));


}
