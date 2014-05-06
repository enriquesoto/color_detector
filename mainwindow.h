#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "colorDetectController.h"
#include "colordetector.h"

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    Mat img_original1;
    Mat img_original2;
    ~MainWindow();
    static QImage Mat2QImage(Mat const& src);
    static Mat QImage2Mat(QImage const& src);
    QString getFileName(QString path);
    

private slots:
    void on_bttLoadImage1_clicked();

    void on_bttnLoadImage2_clicked();

    void on_bttnCompare_clicked();

    void on_sliderThreshold_valueChanged(int value);

private:
    void displayMat(const cv::Mat& image, int numImage);
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
