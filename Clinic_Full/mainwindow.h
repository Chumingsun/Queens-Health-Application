#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStyleFactory>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QTableView>
#include <QDebug>
#include <QPalette>
#include <QRegExp>
#include <QRegExpValidator>
#include <QInputDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
private slots:

    void on_clinicianBookAppointment_clicked();

    void upcomingAppointmentButtonClick();

    void pendingAppointmentButtonClick();

    void on_clinicianToolboxCollapse_clicked();

    void on_clinicianUpcomingAppointmentSendReminder_clicked();

    void on_clinicianBookAppointmentSubmit_clicked();

    void on_clinicianLogin_clicked();

    void on_ClinicianLogout_clicked();

    void on_studentLogin_clicked();

    void on_studentLogout_clicked();

    void on_studentBookAppointmentSubmit_clicked();

    void on_studentBookAppointment_clicked();

    void on_studentToolboxCollapse_clicked();

    void on_studentJoinQueue_clicked();

    void on_studentCancelAppointment_clicked();

    void on_studentNoThanks_clicked();

    void on_studentAppointmentReminderButton_clicked();

    void on_studentSetReminder_clicked();

    void on_studentQuestionnaireButton_clicked();

    void on_studentQuestionnaireSubmit_clicked();

    void on_studentOptionalQuestionnaireButton_clicked();

    void on_studentPostBookingFinish_clicked();

    void on_studentQuestionnaireButtonFromQueue_clicked();

    void on_studentNoThanksFromQueue_clicked();

    void clock();

    void Blink(QWidget *widget);

    void drawQuestionnaire(QString id);

    void drawTable(QString query,QTableView *view);

    void refreshContent();

    void on_adminLogin_clicked();

    void on_adminLogout_clicked();

    void on_mainStack_currentChanged(int arg1);

    void on_adminNewStudentSubmit_clicked();

    void on_adminNewClinicinSubmit_clicked();

    void on_adminNewDoctorSubmit_clicked();

    void on_adminEditStudentSubmit_clicked();

    void on_adminEditClinicianSubmit_clicked();

    void on_adminEditDoctorSubmit_clicked();

    void on_adminEditStudentID_valueChanged(const QString &arg1);

    void on_adminEditClinicianID_valueChanged(const QString &arg1);

    void on_adminEditDoctorID_valueChanged(const QString &arg1);

    void on_adminDoctorSearch_textChanged(const QString &arg1);

    void on_adminClinicianSearch_textChanged(const QString &arg1);

    void on_adminStudentSearch_textChanged(const QString &arg1);

    void on_adminToolBoxCollapse_clicked();

    void on_clinicianGenerateQueue_clicked();

    void on_clinicianDeleteQueue_clicked();

    void on_clinicianViewQueue_clicked();

    void on_clinicianRemovePatientFromQueue_clicked();

    void on_clinicianPendingAppointmentApprove_clicked();

    void on_clinicianPendingAppointmentReject_clicked();

    void on_clinicianUpcomingAppointmentSearch_textChanged(const QString &arg1);

    void on_clinicianPendingAppointmentSearch_textChanged(const QString &arg1);

    void on_doctorLogin_clicked();

    void on_doctorLogout_clicked();

    void on_doctorAppointmentView_activated(const QString &arg1);

    void on_doctorQuestionnaire_clicked();

    void on_doctorQuestionnaireAddQuestion_clicked();

    void on_doctorQuestionnaireDeleteQuestion_clicked();

    void on_doctorQuestionnaireSubmit_clicked();

    void on_doctorQuestionnaireSelectQuestion_activated(const QString &arg1);

    void on_doctorToolboxCollapse_clicked();

    void on_doctorSettings_clicked();

    void on_doctorSettingChangeEmail_clicked();

    void on_doctorSettingChangePassword_clicked();

    void on_doctoerSettingChangeEmailSubmit_clicked();

    void on_doctorSettingChangePasswordSubmit_clicked();

    void on_doctorMessageBox_clicked();

    void on_doctorMessageNewButton_clicked();

    void on_doctorMessageSend_clicked();

    void on_doctorMessageExit_clicked();

    void on_studentQuestionnaireNext_clicked();

    void on_studentQuestionnairePrev_clicked();

    void on_doctorQuestionnaireViewSubmissions_clicked();

    void on_doctorQuestionnaireSubmissionExit_clicked();

    void on_doctorQuestionnaireSubmissionStudent_activated(const QString &arg1);

    void on_studentSettings_clicked();

    void on_studentSettingChangeEmail_clicked();

    void on_studentSettingChangePassword_clicked();

    void on_studentSettingChangeEmailSubmit_clicked();

    void on_studentSettingChangePasswordSubmit_clicked();

    void on_studentMessageBox_clicked();

    void on_studentMessageNewButton_clicked();

    void on_studentMessageSend_clicked();

    void on_studentMessageExit_clicked();

    void on_clinicianSetting_clicked();

    void on_clinicianSettingChangeEmail_clicked();

    void on_clinicianSettingChangePassword_clicked();

    void on_clinicianSettingChangeEmailSubmit_clicked();

    void on_clinicianSettingChangePasswordSubmit_clicked();

    void on_studentAppointmentSearch_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
