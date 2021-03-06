#ifndef REGTOOLBOX_H
#define REGTOOLBOX_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QProgressBar>
#include "tipl/tipl.hpp"
namespace Ui {
class RegToolBox;
}


class RegToolBox : public QMainWindow
{
    Q_OBJECT

public:
    tipl::image<float,3> It,I,J,JJ,I2,It2,J2;
    tipl::image<tipl::vector<3>,3> dis;
    tipl::vector<3> Itvs,Ivs;
    tipl::matrix<4,4,float> ItR;
public:
    tipl::transformation_matrix<double> T;
    tipl::image<float,3> J_view,J_view2;
    tipl::image<tipl::vector<3>,3> dis_view;
public:
    tipl::affine_transform<double> arg;
    tipl::thread thread;
    std::shared_ptr<QTimer> timer;
    std::string status;
public:
    std::shared_ptr<tipl::reg::bfnorm_mapping<float,3> > bnorm_data;
    bool reg_done;
private:
    void clear(void);
    void linear_reg(tipl::reg::reg_type reg_type);
    void nonlinear_reg(void);

public:
    explicit RegToolBox(QWidget *parent = nullptr);
    ~RegToolBox();

private slots:
    void on_OpenTemplate_clicked();

    void on_OpenSubject_clicked();


    void on_run_reg_clicked();
    void on_timer();

    void show_image();
    void on_action_Save_Warpped_Image_triggered();


    void on_reg_type_currentIndexChanged(int index);

    void on_stop_clicked();

    void on_reg_method_currentIndexChanged(int index);

    void on_actionMatch_Intensity_triggered();

    void on_actionRemove_Background_triggered();

    void on_OpenSubject2_clicked();

    void on_OpenTemplate2_clicked();

    void on_actionApply_Warpping_triggered();

    void on_actionSave_Warpping_triggered();

private:
    Ui::RegToolBox *ui;
    QGraphicsScene It_scene,I_scene;
private:
    tipl::color_image cIt,cI,cJ;

};

#endif // REGTOOLBOX_H
