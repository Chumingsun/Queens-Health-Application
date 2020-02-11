#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //database connection
    /*##########################################*/

    /*##########################################*/
    //database connection

        QFile file("DB.cn");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"operation unsuccessfull","Connection File not found!");
            this->close();
        }

        QTextStream in(&file);
        db.setHostName(in.readLine());
        db.setPort(in.readLine().toInt());
        db.setUserName(in.readLine());
        db.setPassword(in.readLine());
        db.setDatabaseName(in.readLine());
        file.close();
        if(db.open())
        {
            //QMessageBox::information(this,"Connection Successful","Successfully Connected To The Database!");

        }
        else {
            QMessageBox::warning(this,"Connection UnSuccessful","Failed to Establish A Database Connection!");

        }

    /*##########################################*/

    /*************GUI*************************/
            qApp->setStyle(QStyleFactory::create("Fusion"));

            QPalette darkPalette;
            QColor *clr = new QColor(241, 194, 255);
            QColor *base = new QColor(255,255,255);
            QColor *highlight = new QColor(255,100,200);
            QColor *bstext = new QColor(87, 11, 110);


            darkPalette.setColor(QPalette::Window, *clr);
            darkPalette.setColor(QPalette::WindowText, *bstext);
            darkPalette.setColor(QPalette::Base, *base);
            darkPalette.setColor(QPalette::AlternateBase, *clr);
            darkPalette.setColor(QPalette::ToolTipBase, *bstext);
            darkPalette.setColor(QPalette::ToolTipText, *bstext);
            darkPalette.setColor(QPalette::Text, *bstext);
            darkPalette.setColor(QPalette::Button, *clr);
            darkPalette.setColor(QPalette::ButtonText, *bstext);
            darkPalette.setColor(QPalette::BrightText, Qt::red);
            darkPalette.setColor(QPalette::Link, *highlight);

            darkPalette.setColor(QPalette::Highlight, *highlight);
            darkPalette.setColor(QPalette::HighlightedText, Qt::white);

            qApp->setPalette(darkPalette);

            qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    /*******************************************/
           // new QRegExpValidator(QRegExp("[A-Za-z0-9#.,/-_=?!@#$%^&*():;+ ]{0,256}"),this)
    /*************Regular Expressions*****************/
    ui->adminUsername->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminNewStudentFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewStudentLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewStudentEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminNewStudentEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminNewClinicianFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewClinicianLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewClinicianEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminNewClinicianEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminNewDoctorFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewDoctorLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminNewDoctorEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminNewDoctorEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminEditStudentFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditStudentLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditStudentEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminEditStudentEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminEditClinicianFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditClinicianLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditClinicianEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminEditClinicianEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminEditDoctorFName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditDoctorLName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->adminEditDoctorEmailName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminEditDoctorEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    ui->adminStudentSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminClinicianSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->adminDoctorSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));

    /********/

    ui->clinicianSettingChangeEmailUser->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->clinicianSettingChangeEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    ui->clinicianPendingAppointmentSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._ ]{0,32}"),this));
    ui->clinicianUpcomingAppointmentSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._ ]{0,32}"),this));

    /*******/
    ui->studentQueueCode->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,10}"),this));
    ui->studentAppointmentSearch->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._ ]{0,32}"),this));
    ui->studentSettingChangeEmailUser->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->studentSettingChangeEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));
    /******/

    ui->doctorQuestionnaireOptionA->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9#.,/-_=?!@#$%^&*():;+ ]{0,64}"),this));
    ui->doctorQuestionnaireOptionB->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9#.,/-_=?!@#$%^&*():;+ ]{0,64}"),this));
    ui->doctorQuestionnaireOptionC->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9#.,/-_=?!@#$%^&*():;+ ]{0,64}"),this));
    ui->doctorQuestionnaireOptionD->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9#.,/-_=?!@#$%^&*():;+ ]{0,64}"),this));
    ui->doctorSettingChangeEmailUser->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._]{0,32}"),this));
    ui->doctorSettingChangeEmailServer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,32}"),this));

    /*************************************************/

    /************************Gui Code*****************************************/
    qApp->setStyle(QStyleFactory::create("Fusion"));
    ui->clinicianBookAppointmentFrame->setHidden(true);
    ui->clinicianPendingAppointmentFrame->setHidden(true);
    ui->clinicianUpcomingAppointmentFrame->setHidden(true);
    ui->clinicianSettingFrame->setHidden(true);
    ui->clinicianQueueFrame->setHidden(true);
    ui->clinicianToolboxCollapse->setHidden(true);

    ui->studentBookAppointmentFrame->setHidden(true);
    ui->studentToolboxCollapse->setHidden(true);
    ui->studentSettingFrame->setHidden(true);
    ui->studentPostBookingFrame->setHidden(true);
    ui->studentAppointmentConfirmantionFrame->setHidden(true);

    ui->clinicianPendingAppointmentID->setHidden(true);

    ui->doctorQuestionnaireFrame->setHidden(true);
    ui->doctorSettingFrame->setHidden(true);

    ui->studentQuestionnaireProgress->setRange(0,100);
    ui->studentQuestionnaireProgress->setValue(0);
    /**********************GUI Code End***************************************/


    /***********************************Starting the clock************************************/
    QTimer *timer = new QTimer(this);
    QString temp = "";
    connect(timer, SIGNAL(timeout()), this, SLOT(clock()));
    timer->start(60000);
    clock();
    /****************************************************************************/
/*****************GUI Code End*****************/





}


MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::upcomingAppointmentButtonClick()
{
    /*****************GUI Code*****************/
        QString appointmentid = dynamic_cast<QPushButton*>(sender())->text().split(" ").at(1);
        qDebug() << appointmentid;
        QSqlQuery query(db);
        query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_id = "+appointmentid+";");
        query.first();
        ui->clinicianUpcomingAppointmentDoctor->setText(query.value(1).toString());
        ui->clinicianUpcomingAppointmentPatient->setText(query.value(2).toString());
        ui->clinicianUpcomingAppointmentDate->setText(query.value(3).toString());
        ui->clinicianUpcomingAppointmentTime->setText(query.value(4).toString());
        ui->clinicianUpcomingAppointmentPresrefil->setText(query.value(5).toString());
        ui->clinicianUpcomingAppointmentEmail->setHtml("This Notification has been Sent To Remind You that Your Appointment with <b>Dr."+ui->clinicianUpcomingAppointmentDoctor->text()+"</b> is due on <b>"+ui->clinicianUpcomingAppointmentDate->text()+" "+ui->clinicianUpcomingAppointmentTime->text()+"</b>, so be prepared and arrive clinic in time.<br>Thank You");

        ui->clinicianBookAppointmentFrame->setHidden(true);
        ui->clinicianPendingAppointmentFrame->setHidden(true);
        ui->clinicianToolboxCollapse->setHidden(false);
        ui->clinicianUpcomingAppointmentFrame->setHidden(false);
    /*****************GUI Code End*****************/
}

void MainWindow::pendingAppointmentButtonClick()
{

    QString appointmentid = dynamic_cast<QPushButton*>(sender())->text().split(" ").at(1);
    qDebug() << appointmentid;
    QSqlQuery query(db);
    query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_id = "+appointmentid+";");
    query.first();
    ui->clinicianPendingAppointmentID->setText(query.value(0).toString());
    ui->clinicianPendingAppointmentDoctor->setText(query.value(1).toString());
    ui->clinicianPendingAppointmentPatient->setText(query.value(2).toString());
    ui->clinicianPendingAppointmentDate->setText(query.value(3).toString());
    ui->clinicianPendingAppointmentTime->setText(query.value(4).toString());
    ui->clinicianPendingAppointmentRefill->setText(query.value(5).toString());


    /*****************GUI Code*****************/
        ui->clinicianBookAppointmentFrame->setHidden(true);
        ui->clinicianUpcomingAppointmentFrame->setHidden(true);
        ui->clinicianToolboxCollapse->setHidden(false);
        ui->clinicianPendingAppointmentFrame->setHidden(false);
    /*****************GUI Code End*****************/
}
void MainWindow::on_clinicianBookAppointment_clicked()
{
        /*****************GUI Code*****************/
        on_clinicianToolboxCollapse_clicked();
        ui->clinicianToolboxCollapse->setHidden(false);
        ui->clinicianBookAppointmentFrame->setHidden(false);
        /*****************GUI Code End*****************/

}

void MainWindow::on_clinicianToolboxCollapse_clicked()
{
    /*****************GUI Code*****************/
    ui->clinicianUpcomingAppointmentFrame->setHidden(true);
    ui->clinicianPendingAppointmentFrame->setHidden(true);
    ui->clinicianBookAppointmentFrame->setHidden(true);
    ui->clinicianSettingFrame->setHidden(true);
    ui->clinicianSettingChangeEmailFrame->setHidden(true);
    ui->clinicianSettingChangePasswordFrame->setHidden(true);
    ui->clinicianToolboxCollapse->setHidden(true);
    ui->clinicianQueueFrame->setHidden(true);
    /*****************GUI Code End*****************/
}

void MainWindow::on_clinicianUpcomingAppointmentSendReminder_clicked()
{
    QSqlQuery query(db);
    query.exec("insert into student_notification values((select student_id from student where student_firstname = '"+ui->clinicianUpcomingAppointmentPatient->text().split(" ").at(0)+"' and student_lastname = '"+ui->clinicianUpcomingAppointmentPatient->text().split(" ").at(1)+"'),'"+ui->clinicianUpcomingAppointmentEmail->toPlainText()+"');");
    qDebug() << query.lastQuery();
    QMessageBox::information(this,"Sent Notification","Reminder Notification Has Been Sent To '"+ui->clinicianUpcomingAppointmentPatient->text()+"'");
}

void MainWindow::on_clinicianBookAppointmentSubmit_clicked()
{

    if(ui->clinicianBookAppointmentDoctor->currentText() == "")
    {
        Blink(ui->clinicianBookAppointmentDoctor);
        return;
    }
    if(!(ui->clinicianBookAppointmentYes->isChecked() || ui->clinicianBookAppointmentNo->isChecked()))
    {
        Blink(ui->clinicianBookAppointmentYes);
        Blink(ui->clinicianBookAppointmentNo);
        return;
    }
    QSqlQuery query(db);
    QString bookDate = QString("%1-%2-%3").arg(ui->clinicianBookAppointmentDate->date().year()).arg(ui->clinicianBookAppointmentDate->date().month()).arg(ui->clinicianBookAppointmentDate->date().day());
    QString bookTime = QString("%1:%2:%3").arg(ui->clinicianBookAppointmentTime->time().hour()).arg(ui->clinicianBookAppointmentTime->time().minute()).arg(0);
    if(ui->clinicianBookAppointmentYes->isChecked())
    {
        query.exec("insert into Appointment(student_id,doctor_id,appointment_date,appointment_time,appointment_pres_refill,appointment_status)values((select student_id from student where student_firstname = '"+ui->clinicianBookAppointmentPatient->currentText().split(" ").at(0)+"' and student_lastname = '"+ui->clinicianBookAppointmentPatient->currentText().split(" ").at(1)+"'),(select doctor_id from doctor where doctor_firstname = '"+ui->clinicianBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->clinicianBookAppointmentDoctor->currentText().split(" ").at(1)+"'),'"+bookDate+"','"+bookTime+"','Yes','Approved')");
    }
    else if(ui->clinicianBookAppointmentNo->isChecked())
    {
        query.exec("insert into Appointment(student_id,doctor_id,appointment_date,appointment_time,appointment_pres_refill,appointment_status)values((select student_id from student where student_firstname = '"+ui->clinicianBookAppointmentPatient->currentText().split(" ").at(0)+"' and student_lastname = '"+ui->clinicianBookAppointmentPatient->currentText().split(" ").at(1)+"'),(select doctor_id from doctor where doctor_firstname = '"+ui->clinicianBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->clinicianBookAppointmentDoctor->currentText().split(" ").at(1)+"'),'"+bookDate+"','"+bookTime+"','No','Approved')");
    }

    refreshContent();
    QMessageBox::information(this,"Operation Successful","Appointment Confirmed!\nAutomated E-Mail Sent!");
}

void MainWindow::on_clinicianLogin_clicked()
{

    ui->clinicianWarning->setText("");

    QSqlQuery query(db);
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
    hash->addData(ui->clinicianPassword->text().toUtf8());
    query.exec("select * from clinician where clinician_id = "+ui->clinicianUsername->text()+";");
    if(query.size() == 1)
    {
        query.first();
        if(query.value("clinician_password").toString() == hash->result().toHex())
        {

            ui->mainStack->setCurrentIndex(1);
            on_clinicianToolboxCollapse_clicked();
            //refreshContent();
            //resizeEvent(new QResizeEvent(size(),size()));

        }
        else{
            ui->clinicianWarning->setText("Invalid Password");
            Blink(ui->clinicianPassword);
        }
    }
    else {
        ui->studentLoginWarning->setText("Invalid UserName");
        Blink(ui->clinicianUsername);
    }


}

void MainWindow::on_ClinicianLogout_clicked()
{
    /*****************GUI Code*****************/
    ui->mainStack->setCurrentIndex(0);
    ui->clinicianUpcomingAppointmentFrame->setHidden(true);
    ui->clinicianPendingAppointmentFrame->setHidden(true);
    ui->clinicianBookAppointmentFrame->setHidden(true);
    ui->clinicianToolboxCollapse->setHidden(true);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentLogin_clicked()
{

    ui->studentLoginWarning->setText("");

    QSqlQuery query(db);
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
    hash->addData(ui->studentLoginPassword->text().toUtf8());
    query.exec("select * from student where student_id = "+ui->studentLoginID->text()+";");
    if(query.size() == 1)
    {
        query.first();
        if(query.value("student_password").toString() == hash->result().toHex())
        {

            ui->mainStack->setCurrentIndex(2);
            QSqlQuery query(db);
            query.exec("select reminder_id from reminder where reminder_for_student = "+ui->studentLoginID->text()+" and reminder_date < curdate();");
            if(query.size() > 0)
            {
                QMessageBox::information(this,"Appointment Alert",QString("You Have %1 Appointment/s Closing in!!\nCheck Your Console for Appointment Details!").arg(query.size()));
            }
            query.exec("select notification_data from student_notification where student_id = "+ui->studentLoginID->text()+";");
            query.first();
            for (int i= 0 ;i<query.size();i++) {
                QMessageBox::information(this,"Notification",query.value(0).toString());
                query.next();
            }
            query.exec("delete from student_notification where student_id = "+ui->studentLoginID->text()+";");

            on_studentToolboxCollapse_clicked();
            //refreshContent();
            //resizeEvent(new QResizeEvent(size(),size()));

        }
        else{
            ui->studentLoginWarning->setText("Invalid Password");
            Blink(ui->studentLoginPassword);
        }
    }
    else {
        ui->studentLoginWarning->setText("Invalid UserName");
        Blink(ui->studentLoginID);
    }

}

void MainWindow::on_studentLogout_clicked()
{
    /*****************GUI Code*****************/
    ui->mainStack->setCurrentIndex(0);
    ui->studentStack->setCurrentIndex(0);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentBookAppointmentSubmit_clicked()
{
    if(ui->studentBookAppointmentDoctor->currentText() == "")
    {
        Blink(ui->studentBookAppointmentDoctor);
        return;
    }
    if(!(ui->studentBookAppointmentYes->isChecked() || ui->studentBookAppointmentNo->isChecked()))
    {
        Blink(ui->studentBookAppointmentYes);
        Blink(ui->studentBookAppointmentNo);
        return;
    }

    QString bookDate = QString("%1-%2-%3").arg(ui->studentBookAppointmentDate->date().year()).arg(ui->studentBookAppointmentDate->date().month()).arg(ui->studentBookAppointmentDate->date().day());
    QString bookTime = QString("%1:%2:%3").arg(ui->studentBookAppointmentTime->time().hour()).arg(ui->studentBookAppointmentTime->time().minute()).arg(0);
    QSqlQuery query(db);
    if(ui->studentBookAppointmentYes->isChecked())
    {
        query.exec("insert into Appointment(student_id,doctor_id,appointment_date,appointment_time,appointment_pres_refill,appointment_status)values("+ui->studentLoginID->text()+",(select doctor_id from doctor where doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"'),'"+bookDate+"','"+bookTime+"','Yes','Pending')");
    }
    else if(ui->studentBookAppointmentNo->isChecked())
    {
        query.exec("insert into Appointment(student_id,doctor_id,appointment_date,appointment_time,appointment_pres_refill,appointment_status)values("+ui->studentLoginID->text()+",(select doctor_id from doctor where doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"'),'"+bookDate+"','"+bookTime+"','No','Pending')");
    }

    /*****************GUI Code*****************/
    ui->studentPostBookingAppointmentDescription->setText("Doctor: "+ ui->studentBookAppointmentDoctor->currentText()+"\nAppointment Date: "+ui->studentBookAppointmentDate->date().toString(Qt::DateFormat::TextDate)+"\nAppointment Time: "+ui->studentBookAppointmentTime->text()+"\nPrescription Refill?:"+((ui->studentBookAppointmentYes->isChecked())?"Yes":"No") );

    ui->studentBookAppointmentFrame->setHidden(true);
    ui->studentAppointmentConfirmantionFrame->setHidden(false);
    ui->studentConfirmationLabel->setText("Thanks For Booking,\nYou will receive a confirmation Notification\nOnce Your Appointment is Confimed!\n\nFeel Free to Fill Out Health Questionnaire\nBefore Your Appointment!");

    ui->studentQuestionnaireButtonFromQueue->setHidden(true);
    ui->studentNoThanksFromQueue->setHidden(true);
    ui->studentQuestionnaireButton->setHidden(false);
    ui->studentNoThanks->setHidden(false);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentBookAppointment_clicked()
{
    /******GUI Code****/
    on_studentToolboxCollapse_clicked();
    ui->studentBookAppointmentFrame->setHidden(false);
    ui->studentToolboxCollapse->setHidden(false);
   /*****************GUI Code End*****************/

    //Student appointment booking code here



}

void MainWindow::on_studentToolboxCollapse_clicked()
{
    /*****************GUI Code*****************/
    ui->studentAppointmentConfirmantionFrame->setHidden(true);
    ui->studentBookAppointmentFrame->setHidden(true);
    ui->studentPostBookingFrame->setHidden(true);
    ui->studentSettingFrame->setHidden(true);
    ui->studentSettingChangeEmailFrame->setHidden(true);
    ui->studentSettingChangePasswordFrame->setHidden(true);
    ui->studentToolboxCollapse->setHidden(true);

    /*****************GUI Code End*****************/
}

void MainWindow::on_studentJoinQueue_clicked()
{
    QSqlQuery query(db);
    query.exec("select queue_code from queue_content where student_id = "+ui->studentLoginID->text()+";");
    if(query.size()>0)
    {
        QMessageBox::warning(this,"Operation Failed","You Are Already In a Queue!\nYou cannot join multiple queues at once.");
        ui->studentQueueCode->setText("");
        return;
    }
    query.exec("select queue_code from queue where queue_code = "+ui->studentQueueCode->text()+";");

    if(ui->studentQueueCode->text() == "" || query.size() == 0)//Your Field checking, I am only checking is it empty or not.
    {
        if(QMessageBox::question(this,"Invalid Queue Code","Error With Queue Code.\nRetry?") == QMessageBox::Yes)
        {
            return;
        }
        else{
            ui->studentQueueCode->setText("");
        }
    }
    else if(query.size() == 1){//if queue code is correct
        query.exec("insert into queue_content(queue_code,student_id)values("+ui->studentQueueCode->text()+","+ui->studentLoginID->text()+");");

        ui->studentConfirmationLabel->setText(QString("CurrentQueue: %1\n\n\nYou're Now in the Queue!\nKeep Track of the Queue from the Home Screen!\n\nFeel Free to Fill Out Health Questionnaire\nBefore Your Appointment!").arg(ui->studentQueueCode->text()));
        refreshContent();
        ui->studentBookAppointmentFrame->setHidden(true);
        ui->studentAppointmentConfirmantionFrame->setHidden(false);
        ui->studentToolboxCollapse->setHidden(false);
        ui->studentQuestionnaireButtonFromQueue->setHidden(false);
        ui->studentNoThanksFromQueue->setHidden(false);
        ui->studentQuestionnaireButton->setHidden(true);
        ui->studentNoThanks->setHidden(true);

    }

}

void MainWindow::on_studentCancelAppointment_clicked()
{
    if(QMessageBox::question(this,"Cancel Appointment","Are You Sure?\nYou Want To Cancel This Appointment.") == QMessageBox::Yes)
    {
        QSqlQuery query(db);
        query.exec("select max(appointment_id) from appointment where student_id = "+ui->studentLoginID->text()+";");
        query.first();
        query.exec("delete from appointment where appointment_id = "+query.value(0).toString()+";");
        QMessageBox::information(this,"Operation Successful","Your Appointment Has Been Successfully Cannelled!");
        ui->studentToolboxCollapse->clicked(true);

    }
    else{
        //Do nothing
    }
}

void MainWindow::on_studentNoThanks_clicked()
{
    /*****************GUI Code*****************/
    ui->studentAppointmentConfirmantionFrame->setHidden(true);
    ui->studentPostBookingFrame->setHidden(false);
    ui->studentReminderFrame->setHidden(true);
    ui->studentOptionalQuestionnaireButton->setHidden(false);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentAppointmentReminderButton_clicked()
{
    /*****************GUI Code*****************/
    if(ui->studentReminderFrame->isHidden())
    {
        ui->studentReminderFrame->setHidden(false);
    }
    else
    {
        ui->studentReminderFrame->setHidden(true);
    }
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentSetReminder_clicked()
{
    if(ui->studentReminderDaysBefore->currentText() == "None" && ui->studentReminderWeeksBefore->currentText() == "None")
    {
        Blink(ui->studentReminderWeeksBefore);
        Blink(ui->studentReminderDaysBefore);
        return;
    }
    QSqlQuery query(db);
    QString bookDate = QString("%1-%2-%3").arg(ui->studentBookAppointmentDate->date().year()).arg(ui->studentBookAppointmentDate->date().month()).arg(ui->studentBookAppointmentDate->date().day());
    if(ui->studentReminderWeeksBefore->currentText() != "None")
    {
        query.exec("insert into reminder(reminder_for_student,reminder_date)values("+ui->studentLoginID->text()+",date_sub('"+bookDate+"',interval "+ui->studentReminderWeeksBefore->currentText()+" week));");
    }

    if(ui->studentReminderDaysBefore->currentText() != "None")
    {
        query.exec("insert into reminder(reminder_for_student,reminder_date)values("+ui->studentLoginID->text()+",date_sub('"+bookDate+"',interval "+ui->studentReminderDaysBefore->currentText()+" day));");
    }
    QMessageBox::information(this,"Operation Successful","Reminder Set Successully!");
    /*****************GUI Code*****************/
    ui->studentReminderFrame->setHidden(true);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentQuestionnaireButton_clicked()
{
    /*****************GUI Code*****************/
    ui->studentStack->setCurrentIndex(1);
    ui->studentAppointmentConfirmantionFrame->setHidden(true);
    ui->studentPostBookingFrame->setHidden(false);
    ui->studentReminderFrame->setHidden(true);
    ui->studentOptionalQuestionnaireButton->setHidden(true);
    /*****************GUI Code End*****************/
    QSqlQuery query(db);
    query.exec("select d.doctor_id from questionnaire_submissions as qs join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join questionnaire as q on qq.questionnaire_id = q.questionnaire_id join doctor as d on q.questionnaire_doctor = d.doctor_id where student_id = "+ui->studentLoginID->text()+" and d.doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and d.doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"';");
    if(query.size() > 0)
    {
        QMessageBox::information(this,"Questionnaire","Thank You For Your Interest!\n But It Looks Like You Have Already Submitted The Questionnaire of Dr. "+ui->studentBookAppointmentDoctor->currentText());
        ui->studentStack->setCurrentIndex(0);
        return;
    }
    query.exec("select doctor_id from doctor where doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"';");
    query.first();
    drawQuestionnaire(query.value(0).toString());


}

void MainWindow::on_studentQuestionnaireSubmit_clicked()
{
    QSqlQuery query(db);
    for(int i = 0;i < ui->studentQuestionnaireStack->count(); i++)
    {
        for(int j = 1 ; j < ui->studentQuestionnaireStack->widget(i)->layout()->count(); j+=2)
        {
            QString questionID = (dynamic_cast<QLabel*>(ui->studentQuestionnaireStack->widget(i)->layout()->itemAt(j)->widget()))->text().split(" ").at(0);

            if((dynamic_cast<QRadioButton*>(ui->studentQuestionnaireStack->widget(i)->layout()->itemAt(j+1)->widget()))->isChecked()){

                QString optionID = (dynamic_cast<QLabel*>(ui->studentQuestionnaireStack->widget(i)->layout()->itemAt(j)->widget()))->text().split(" ").at(1);

                query.exec("insert into questionnaire_submissions values("+questionID+","+ui->studentLoginID->text()+","+optionID+")");

            }

        }
    }
    QMessageBox::information(this,"Operation Successfull","Questionnaire Submitted Successfully!");
    //submission.
    /*****************GUI Code*****************/
    ui->studentStack->setCurrentIndex(0);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentOptionalQuestionnaireButton_clicked()
{
    /*****************GUI Code*****************/
    ui->studentOptionalQuestionnaireButton->setHidden(true);
    ui->studentStack->setCurrentIndex(1);
    /*****************GUI Code End*****************/
    QSqlQuery query(db);
    query.exec("select d.doctor_id from questionnaire_submissions as qs join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join questionnaire as q on qq.questionnaire_id = q.questionnaire_id join doctor as d on q.questionnaire_doctor = d.doctor_id where student_id = "+ui->studentLoginID->text()+" and d.doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and d.doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"';");
    if(query.size() > 0)
    {
        QMessageBox::information(this,"Questionnaire","Thank You For Your Interest!\n But It Looks Like You Have Already Submitted The Questionnaire of Dr. "+ui->studentBookAppointmentDoctor->currentText());
        ui->studentStack->setCurrentIndex(0);
        return;
    }
    query.exec("select doctor_id from doctor where doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"';");
    query.first();
    drawQuestionnaire(query.value(0).toString());

}

void MainWindow::on_studentPostBookingFinish_clicked()
{
    /*****************GUI Code*****************/
    ui->studentToolboxCollapse->clicked(true);
    ui->studentOptionalQuestionnaireButton->setHidden(false);
    /*****************GUI Code End*****************/
}

void MainWindow::on_studentQuestionnaireButtonFromQueue_clicked()
{
    /*****************GUI Code*****************/
    ui->studentToolboxCollapse->clicked(true);
    ui->studentStack->setCurrentIndex(1);
    /*****************GUI Code End*****************/
    QSqlQuery query(db);
    query.exec("select d.doctor_id from questionnaire_submissions as qs join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join questionnaire as q on qq.questionnaire_id = q.questionnaire_id join doctor as d on q.questionnaire_doctor = d.doctor_id where student_id = "+ui->studentLoginID->text()+" and d.doctor_id = "+ui->studentConfirmationLabel->text().split(" ").at(1)+";");
    if(query.size() > 0)
    {
        QMessageBox::information(this,"Questionnaire","Thank You For Your Interest!\n But It Looks Like You Have Already Submitted The Questionnaire of Dr. "+ui->studentBookAppointmentDoctor->currentText());
        return;
    }
    query.exec("select doctor_id from doctor where doctor_firstname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentBookAppointmentDoctor->currentText().split(" ").at(1)+"';");
    query.first();
    drawQuestionnaire(query.value(0).toString());


}

void MainWindow::on_studentNoThanksFromQueue_clicked()
{
    /*****************GUI Code*****************/
    ui->studentToolboxCollapse->clicked(true);
    /*****************GUI Code End*****************/
}

/*****************GUI Code*****************/
void MainWindow::clock()
{
    QTime *timer = new QTime();
    timer->start();

    QDate *date = new QDate();
    QLocale *local = new QLocale;
    QString dat = local->monthName(date->currentDate().month()) + " " + QString("%1, %2").arg(date->currentDate().day()).arg(date->currentDate().year());

    ui->Time_Date_clinician->setText(dat);
    ui->Time_Date_student->setText(dat);
    ui->Time_Date_admin->setText(dat);
    ui->Time_Date_doctor->setText(dat);


    if(timer->minute() > 9 && timer->hour() > 9)
    {
        QString tim = QString("%1:%2").arg(timer->hour()).arg(timer->minute());
        ui->Time_Time_clinician->setText(tim);
        ui->Time_Time_student->setText(tim);
        ui->Time_Time_admin->setText(tim);
        ui->Time_Time_doctor->setText(tim);
    }
    else if(timer->minute() < 10 && timer->hour() > 9){

        QString tim = QString("%1:0%2").arg(timer->hour()).arg(timer->minute());
        ui->Time_Time_clinician->setText(tim);
        ui->Time_Time_student->setText(tim);
        ui->Time_Time_admin->setText(tim);
        ui->Time_Time_doctor->setText(tim);

    }
    else if (timer->minute() < 10 && timer->hour() < 10) {
        QString tim = QString("0%1:0%2").arg(timer->hour()).arg(timer->minute());
        ui->Time_Time_clinician->setText(tim);
        ui->Time_Time_student->setText(tim);
        ui->Time_Time_admin->setText(tim);
        ui->Time_Time_doctor->setText(tim);
    }
    else if (timer->minute() > 9 && timer->hour() < 10) {
        QString tim = QString("0%1:%2").arg(timer->hour()).arg(timer->minute());
        ui->Time_Time_clinician->setText(tim);
        ui->Time_Time_student->setText(tim);
        ui->Time_Time_admin->setText(tim);
        ui->Time_Time_doctor->setText(tim);
    }

}

void MainWindow::Blink(QWidget *widget)
{
    QString style = widget->styleSheet();

    for(int i=0;i<=500;i++)
    {
        if(i%500 < 250)
        {
            widget->setStyleSheet(style);
            widget->repaint();

        }
        else {
            widget->setStyleSheet("border: 4px solid #FF0000;");
            widget->repaint();
        }

    }
    widget->setFocus();
    return;
}

void MainWindow::drawQuestionnaire(QString id)
{
    QSqlQuery query(db);
    query.exec("select questionnaire_question_id,questionnaire_question from questionnaire_question where questionnaire_id = (select questionnaire_id from questionnaire where questionnaire_doctor = "+id+");");
    query.first();
    if(query.size() < 1)
    {
        QMessageBox::information(this,"No Questionnaire","Thanks For The Effort\nBut The Doctor Have Not Designed Any Questionnaire!");
        ui->studentStack->setCurrentIndex(0);
        return;
    }
    for (int i = 0;i < ui->studentQuestionnaireStack->count();i++) {//clearing the questionnairestack
        QWidget *widget = ui->studentQuestionnaireStack->widget(i);
        ui->studentQuestionnaireStack->removeWidget(widget);
        widget->deleteLater();

    }

    for(int i = 0;i < query.size();i++)
    {
        QSqlQuery query2(db);
        query2.exec("select questionnaire_option,questionnaire_option_id from questionnaire_options where questionnaire_question_id = "+query.value(0).toString()+";");
        query2.first();
        QWidget *screen = new QWidget;
        ui->studentQuestionnaireStack->addWidget(screen);
        QVBoxLayout *layout = new QVBoxLayout();
        screen->setLayout(layout);
        QLabel *question = new QLabel(QString("Q%1 ) %2").arg(i+1).arg(query.value(1).toString()));//appointment data
        const QFont *font = new QFont("Impact",15);
        question->setFont(*font);
        layout->addWidget(question);
        for(int j = 0 ;j < query2.size();j++)
        {
            QRadioButton *option = new QRadioButton(query2.value(0).toString(),screen);
            QLabel *qoid = new QLabel(query.value(0).toString() + " " + query2.value(1).toString());
            qoid->setHidden(true);
            layout->addWidget(qoid);
            layout->addWidget(option);
            query2.next();
        }

        /*connect(button,SIGNAL(clicked()),this,SLOT(upcomingAppointmentButtonClick()));
        layout->addWidget( button );*/
        query.next();


    }
}

void MainWindow::drawTable(QString query,QTableView *view){

    if(view->model() != nullptr)
        view->model()->deleteLater();

    QSqlQueryModel *table = new QSqlQueryModel();
    table->setQuery(query);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(table);
    view->setModel(proxyModel);
    view->setSortingEnabled(true);

    const QFont *font = new QFont("Rockwell Extra Bold",12);
    view->horizontalHeader()->setFont(*font);
    const QFont *font2 = new QFont("Georgia",10);
    view->setFont(*font2);
    view->resizeRowsToContents();
    view->resizeColumnsToContents();
}

void MainWindow::refreshContent(){
    on_mainStack_currentChanged(ui->mainStack->currentIndex());
}

/*****************GUI Code End*****************/

void MainWindow::on_adminLogin_clicked()
{
    ui->adminWarning->setText("");

    QSqlQuery query(db);
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
    hash->addData(ui->adminPassword->text().toUtf8());
    query.exec("select * from admin where username = '"+ui->adminUsername->text()+"';");
    if(query.size() == 1)
    {
        query.first();
        if(query.value("ssap").toString() == hash->result().toHex())
        {

            ui->mainStack->setCurrentIndex(3);
            //refreshContent();
            //resizeEvent(new QResizeEvent(size(),size()));
        }
        else{
            ui->adminWarning->setText("Invalid Password");
            Blink(ui->adminPassword);
        }
    }
    else {
        ui->adminWarning->setText("Invalid UserName");
        Blink(ui->adminUsername);
    }
}

void MainWindow::on_adminLogout_clicked()
{
    ui->mainStack->setCurrentIndex(0);
}

void MainWindow::on_mainStack_currentChanged(int arg1)
{
    switch(arg1)
    {
        case 0:
        {
            ui->studentLoginID->setValue(0);
            ui->studentLoginPassword->setText("");
            ui->studentLoginWarning->setText("");
            ui->clinicianUsername->setValue(0);
            ui->clinicianPassword->setText("");
            ui->clinicianWarning->setText("");
            ui->adminUsername->setText("");
            ui->adminPassword->setText("");
            ui->adminWarning->setText("");
        break;
        }
        case 1:
        {
            ui->clinicianBookAppointmentDate->setDate(QDate::currentDate());
            ui->clinicianBookAppointmentTime->setTime(QTime::currentTime());
            ui->clinicianBookAppointmentDoctor->setCurrentIndex(0);
            ui->clinicianBookAppointmentPatient->setCurrentIndex(0);
            ui->clinicianBookAppointmentYes->setAutoExclusive(false);
            ui->clinicianBookAppointmentYes->setChecked(false);
            ui->clinicianBookAppointmentYes->setAutoExclusive(true);

            ui->clinicianBookAppointmentNo->setAutoExclusive(false);
            ui->clinicianBookAppointmentNo->setChecked(false);
            ui->clinicianBookAppointmentNo->setAutoExclusive(true);
            ui->clinicianUpcomingAppointmentSearch->setText("");
            ui->clinicianPendingAppointmentSearch->setText("");
            /*********************filling doctors************************************/
            QSqlQuery query(db);
            query.exec("select concat(doctor_firstname ,' ', doctor_lastname) as doct from doctor;");
            query.first();
            ui->clinicianBookAppointmentDoctor->clear();
            ui->clinicianGenerateQueueDoctor->clear();
            ui->clinicianGenerateQueueDoctor->addItem("==Select Doctor==");
            for(int i = 0;i<query.size();i++)
            {
                ui->clinicianBookAppointmentDoctor->addItem(query.value(0).toString());
                ui->clinicianGenerateQueueDoctor->addItem(query.value(0).toString());
                query.next();
            }

            /***************************************************/
            /***************filling students********************/
            query.exec("select concat(student_firstname,' ',student_lastname) as stud from student;");
            query.first();
            ui->clinicianBookAppointmentPatient->clear();
            for(int i = 0;i<query.size();i++)
            {
                    ui->clinicianBookAppointmentPatient->addItem(query.value(0).toString());
                    query.next();
            }
            /***************************************************/

            /****************filling queue codes**************/
            query.exec("select queue_code from queue;");
            query.first();
            ui->clinicianDeleteQueueCode->clear();
            for(int i= 0;i<query.size();i++){
                ui->clinicianDeleteQueueCode->addItem(query.value(0).toString());
                query.next();
            }
            /************************************************/

            /**********clinician upcoming List***************/



            ui->clinicianUpcomingAppointmentList->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->clinicianUpcomingAppointmentList->setWidgetResizable( true );

            QWidget *widget = new QWidget();
            ui->clinicianUpcomingAppointmentList->setWidget( widget );

            QVBoxLayout *layout = new QVBoxLayout();
            widget->setLayout( layout );

            query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.appointment_date between curdate() and date_add(curdate(),interval 7 day) order by (a.appointment_date);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString( "Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//appointment data
                connect(button,SIGNAL(clicked()),this,SLOT(upcomingAppointmentButtonClick()));
                layout->addWidget( button );
                query.next();
            }

            /************clinician pending List***********/

            ui->clinicianPendingAppointmentList->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->clinicianPendingAppointmentList->setWidgetResizable( true );

            QWidget *widget2 = new QWidget();
            ui->clinicianPendingAppointmentList->setWidget( widget2 );

            QVBoxLayout *layout2 = new QVBoxLayout();
            widget2->setLayout( layout2 );
            query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Pending' order by (a.appointment_date);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString( "Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );
                connect(button,SIGNAL(clicked()),this,SLOT(pendingAppointmentButtonClick()));
                layout2->addWidget( button );
                query.next();
            }



            /*****************GUI Code*****************/
            on_clinicianToolboxCollapse_clicked();
            /*****************GUI Code End*****************/
            break;
        }
        case 2:
        {
            ui->studentBookAppointmentDate->setDate(QDate::currentDate());
            ui->studentBookAppointmentTime->setTime(QTime::currentTime());
            ui->studentBookAppointmentYes->setAutoExclusive(false);
            ui->studentBookAppointmentYes->setChecked(false);
            ui->studentBookAppointmentYes->setAutoExclusive(true);

            ui->studentBookAppointmentNo->setAutoExclusive(false);
            ui->studentBookAppointmentNo->setChecked(false);
            ui->studentBookAppointmentNo->setAutoExclusive(true);


            ui->studentAppointmentSearch->setText("");
            ui->studentQueueCode->setText("");
            ui->studentReminderWeeksBefore->setCurrentIndex(0);
            ui->studentReminderDaysBefore->setCurrentIndex(0);

            /****************Student Appointments*****************/
            ui->studentAppointments->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->studentAppointments->setWidgetResizable( true );

            QWidget *widget3 = new QWidget();
            ui->studentAppointments->setWidget( widget3 );

            QVBoxLayout *layout3 = new QVBoxLayout();
            widget3->setLayout( layout3 );
            QSqlQuery query(db);
            query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.student_id = "+ui->studentLoginID->text()+" order by (a.appointment_date);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString("Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//dummy appointment data
                layout3->addWidget( button );
                query.next();
            }

            /****************Student Queue*****************/
            ui->studentCurrentQueue->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->studentCurrentQueue->setWidgetResizable( true );

            QWidget *widget4 = new QWidget();
            ui->studentCurrentQueue->setWidget( widget4 );

            QVBoxLayout *layout4 = new QVBoxLayout();
            widget4->setLayout( layout4 );
            query.exec("select student_lastname,entered_queue_at from queue_content as q join student as s on q.student_id = s.student_id where queue_code = (select queue_code from queue_content where student_id = "+ui->studentLoginID->text()+") order by(entered_queue_at);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString( "Queue No: %1\n\nPatient Name: Mr/Mrs. %2\nEntered Queue At: %3" ).arg( i ).arg(query.value(0).toString()).arg(query.value(1).toString()) );//dummy appointment data
                layout4->addWidget( button );
                query.next();
            }

            /*********************filling doctors************************************/

            query.exec("select concat(doctor_firstname ,' ', doctor_lastname) as doct from doctor;");
            query.first();
            ui->studentBookAppointmentDoctor->clear();
            for(int i = 0;i<query.size();i++)
            {
                ui->studentBookAppointmentDoctor->addItem(query.value(0).toString());
                query.next();
            }

            /***************************************************/
            /*****************GUI Code*****************/
            //ui->studentStack->setCurrentIndex(1);
            ui->mainStack->setCurrentIndex(2);
            ui->studentStack->setCurrentIndex(0);

            ui->studentBookAppointmentFrame->setHidden(true);
            ui->studentToolboxCollapse->setHidden(true);
            ui->studentAppointmentConfirmantionFrame->setHidden(true);
            ui->studentSettingFrame->setHidden(true);
            ui->studentPostBookingFrame->setHidden(true);
            /*****************GUI Code End*****************/
            break;
        }
        case 3:
        {
            /**********cleaning up fields**************/
            ui->adminNewDoctorFName->setText("");
            ui->adminNewDoctorLName->setText("");
            ui->adminNewDoctorEmailName->setText("");
            ui->adminNewDoctorEmailServer->setText("");
            ui->adminNewDoctorDepartment->setCurrentIndex(0);
            ui->adminNewStudentFName->setText("");
            ui->adminNewStudentLName->setText("");
            ui->adminNewStudentEmailName->setText("");
            ui->adminNewStudentEmailServer->setText("");
            ui->adminNewClinicianFName->setText("");
            ui->adminNewClinicianLName->setText("");
            ui->adminNewClinicianEmailName->setText("");
            ui->adminNewClinicianEmailServer->setText("");

            ui->adminEditDoctorFName->setText("");
            ui->adminEditDoctorLName->setText("");
            ui->adminEditDoctorEmailName->setText("");
            ui->adminEditDoctorEmailServer->setText("");
            ui->adminEditDoctorDepartment->setCurrentIndex(0);
            ui->adminEditStudentFName->setText("");
            ui->adminEditStudentLName->setText("");
            ui->adminEditStudentEmailName->setText("");
            ui->adminEditStudentEmailServer->setText("");
            ui->adminEditClinicianFName->setText("");
            ui->adminEditClinicianLName->setText("");
            ui->adminEditClinicianEmailName->setText("");
            ui->adminEditClinicianEmailServer->setText("");

            ui->adminDoctorSearch->setText("");
            ui->adminStudentSearch->setText("");
            ui->adminClinicianSearch->setText("");
         /*********************************************************/

         /**********************Filling admin tables*******************/
            drawTable("select doctor_id as 'ID',doctor_firstname as 'First Name',doctor_lastName as 'Last Name',doctor_Email as 'E-Mail',doctor_department as 'Department' from Doctor;",ui->adminDoctorTable);
            drawTable("select clinician_id as 'ID',clinician_firstname as 'First Name',clinician_lastName as 'Last Name',clinician_Email as 'E-Mail' from clinician;",ui->adminClinicianTable);
            drawTable("select student_id as 'ID',student_firstname as 'First Name',student_lastName as 'Last Name',student_Email as 'E-Mail' from Student;",ui->adminStudentTable);
         /***************************************************/

            break;
        }
        case 4:
        {
            /***********************RESETTING FIELD****************************/
            ui->doctorAppointmentView->setCurrentIndex(0);
            /******************************************************************/

            QSqlQuery query(db);
            /****************Doctor Queue*****************/
            ui->doctorPatientQueue->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->doctorPatientQueue->setWidgetResizable( true );

            QWidget *widget4 = new QWidget();
            ui->doctorPatientQueue->setWidget( widget4 );

            QVBoxLayout *layout4 = new QVBoxLayout();
            widget4->setLayout( layout4 );

            query.exec("select student_lastname,entered_queue_at from queue_content as q join student as s on q.student_id = s.student_id where queue_code = (select queue_code from queue where queue_for_doctor = "+ui->doctorLoginID->text()+") order by(entered_queue_at);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString( "Queue No: %1\n\nPatient Name: Mr/Mrs. %2\nEntered Queue At: %3" ).arg( i ).arg(query.value(0).toString()).arg(query.value(1).toString()) );//dummy appointment data
                layout4->addWidget( button );
                query.next();
            }

            /****************Doctor Appointments*****************/
            ui->doctorAppointments->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
            ui->doctorAppointments->setWidgetResizable( true );

            QWidget *widget3 = new QWidget();
            ui->doctorAppointments->setWidget( widget3 );

            QVBoxLayout *layout3 = new QVBoxLayout();
            widget3->setLayout( layout3 );
            query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.doctor_id = "+ui->doctorLoginID->text()+" and a.appointment_date = curdate() order by (a.appointment_date);");
            query.first();
            for (int i = 0; i < query.size(); i++)
            {
                QPushButton *button = new QPushButton( QString("Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//dummy appointment data
                layout3->addWidget( button );
                query.next();
            }
            break;
        }

    }
}

void MainWindow::on_adminNewStudentSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminNewStudentFName->text() == "")
    {
        Blink(ui->adminNewStudentFName);
        return;
    }
    if(ui->adminNewStudentLName->text() == "")
    {
        Blink(ui->adminNewStudentLName);
        return;
    }
    if(ui->adminNewStudentEmailName->text() == "" || ui->adminNewStudentEmailServer->text() == "")
    {
        Blink(ui->adminNewStudentEmailName);
        Blink(ui->adminNewStudentEmailServer);
        return;
    }

    /*************************************/
    QSqlQuery query(db);
    query.exec("insert into student(student_firstname,student_lastname,student_email)values('"+ui->adminNewStudentFName->text()+"','"+ui->adminNewStudentLName->text()+"','"+ui->adminNewStudentEmailName->text()+"@"+ui->adminNewStudentEmailServer->text()+".com"+"');");
    refreshContent();
}

void MainWindow::on_adminNewClinicinSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminNewClinicianFName->text() == "")
    {
        Blink(ui->adminNewClinicianFName);
        return;
    }
    if(ui->adminNewClinicianLName->text() == "")
    {
        Blink(ui->adminNewClinicianLName);
        return;
    }
    if(ui->adminNewClinicianEmailName->text() == "" || ui->adminNewClinicianEmailServer->text() == "")
    {
        Blink(ui->adminNewClinicianEmailName);
        Blink(ui->adminNewClinicianEmailServer);
        return;
    }

    /*************************************/
    QSqlQuery query(db);
    query.exec("insert into Clinician(Clinician_firstname,Clinician_lastname,Clinician_email)values('"+ui->adminNewClinicianFName->text()+"','"+ui->adminNewClinicianLName->text()+"','"+ui->adminNewClinicianEmailName->text()+"@"+ui->adminNewClinicianEmailServer->text()+".com"+"');");
    refreshContent();
}

void MainWindow::on_adminNewDoctorSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminNewDoctorFName->text() == "")
    {
        Blink(ui->adminNewDoctorFName);
        return;
    }
    if(ui->adminNewDoctorLName->text() == "")
    {
        Blink(ui->adminNewDoctorLName);
        return;
    }
    if(ui->adminNewDoctorEmailName->text() == "" || ui->adminNewDoctorEmailServer->text() == "")
    {
        Blink(ui->adminNewDoctorEmailName);
        Blink(ui->adminNewDoctorEmailServer);
        return;
    }

    /*************************************/
    QSqlQuery query(db);
    query.exec("insert into Doctor(Doctor_firstname,Doctor_lastname,Doctor_email,Doctor_department)values('"+ui->adminNewDoctorFName->text()+"','"+ui->adminNewDoctorLName->text()+"','"+ui->adminNewDoctorEmailName->text()+"@"+ui->adminNewDoctorEmailServer->text()+".com"+"','"+ui->adminNewDoctorDepartment->currentText()+"');");
    refreshContent();
}

void MainWindow::on_adminEditStudentSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminEditStudentFName->text() == "")
    {
        Blink(ui->adminEditStudentFName);
        return;
    }
    if(ui->adminEditStudentLName->text() == "")
    {
        Blink(ui->adminEditStudentLName);
        return;
    }
    if(ui->adminEditStudentEmailName->text() == "" || ui->adminEditStudentEmailServer->text() == "")
    {
        Blink(ui->adminEditStudentEmailName);
        Blink(ui->adminEditStudentEmailServer);
        return;
    }

    QSqlQuery query(db);
    query.exec("select * from student where student_id = "+ui->adminEditStudentID->text()+";");
    if(query.size() != 1)
    {
        Blink(ui->adminEditStudentID);
        return;
    }
    /*************************************/
    if(QMessageBox::question(this,"Confirmation","Are You Sure You Want To Update This Record?") == QMessageBox::Yes){
        query.exec("update student set student_firstname = '"+ui->adminEditStudentFName->text()+"',student_lastname = '"+ui->adminEditStudentLName->text()+"', student_email = '"+ui->adminEditStudentEmailName->text()+"@"+ui->adminEditStudentEmailServer->text()+".com"+"' where student_id = "+ui->adminEditStudentID->text()+";");
        QMessageBox::information(this,"Operation Successful!","Account Updated Successfully!");
    }
    refreshContent();
}

void MainWindow::on_adminEditClinicianSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminEditClinicianFName->text() == "")
    {
        Blink(ui->adminEditClinicianFName);
        return;
    }
    if(ui->adminEditClinicianLName->text() == "")
    {
        Blink(ui->adminEditClinicianLName);
        return;
    }
    if(ui->adminEditClinicianEmailName->text() == "" || ui->adminEditClinicianEmailServer->text() == "")
    {
        Blink(ui->adminEditClinicianEmailName);
        Blink(ui->adminEditClinicianEmailServer);
        return;
    }

    QSqlQuery query(db);
    query.exec("select * from Clinician where Clinician_id = "+ui->adminEditClinicianID->text()+";");
    if(query.size() != 1)
    {
        Blink(ui->adminEditClinicianID);
        return;
    }
    /*************************************/
    if(QMessageBox::question(this,"Confirmation","Are You Sure You Want To Update This Record?") == QMessageBox::Yes){
        query.exec("update Clinician set Clinician_firstname = '"+ui->adminEditClinicianFName->text()+"',Clinician_lastname = '"+ui->adminEditClinicianLName->text()+"', Clinician_email = '"+ui->adminEditClinicianEmailName->text()+"@"+ui->adminEditClinicianEmailServer->text()+".com"+"' where clinician_id = "+ui->adminEditClinicianID->text()+";");
        QMessageBox::information(this,"Operation Successful!","Account Updated Successfully!");
    }
    refreshContent();
}

void MainWindow::on_adminEditDoctorSubmit_clicked()
{
    /***********checks*****************/
    if(ui->adminEditDoctorFName->text() == "")
    {
        Blink(ui->adminEditDoctorFName);
        return;
    }
    if(ui->adminEditDoctorLName->text() == "")
    {
        Blink(ui->adminEditDoctorLName);
        return;
    }
    if(ui->adminEditDoctorEmailName->text() == "" || ui->adminEditDoctorEmailServer->text() == "")
    {
        Blink(ui->adminEditDoctorEmailName);
        Blink(ui->adminEditDoctorEmailServer);
        return;
    }

    QSqlQuery query(db);
    query.exec("select * from Doctor where Doctor_id = "+ui->adminEditDoctorID->text()+";");
    if(query.size() != 1)
    {
        Blink(ui->adminEditDoctorID);
        return;
    }
    /*************************************/
    if(QMessageBox::question(this,"Confirmation","Are You Sure You Want To Update This Record?") == QMessageBox::Yes){
        query.exec("update Doctor set Doctor_firstname = '"+ui->adminEditDoctorFName->text()+"',Doctor_lastname = '"+ui->adminEditDoctorLName->text()+"', Doctor_email = '"+ui->adminEditDoctorEmailName->text()+"@"+ui->adminEditDoctorEmailServer->text()+".com"+"',doctor_department = '"+ui->adminEditDoctorDepartment->currentText()+"' where doctor_id = "+ui->adminEditDoctorID->text()+";");
        QMessageBox::information(this,"Operation Successful!","Account Updated Successfully!");
    }
    refreshContent();
}

void MainWindow::on_adminEditStudentID_valueChanged(const QString &arg1)
{
    QSqlQuery query(db);
    query.exec("select * from student where student_id = "+arg1+";");
    query.first();
    if(query.size() > 0)
    {
        ui->adminEditStudentFName->setText(query.value("student_firstname").toString());
        ui->adminEditStudentLName->setText(query.value("student_lastname").toString());
        ui->adminEditStudentEmailName->setText(query.value("student_Email").toString().split("@").at(0));
        ui->adminEditStudentEmailServer->setText(query.value("student_Email").toString().split("@").at(1).split(".").at(0));
    }
    else{
        ui->adminEditStudentFName->setText("");
        ui->adminEditStudentLName->setText("");
        ui->adminEditStudentEmailName->setText("");
        ui->adminEditStudentEmailServer->setText("");
    }

}

void MainWindow::on_adminEditClinicianID_valueChanged(const QString &arg1)
{
    QSqlQuery query(db);
    query.exec("select * from Clinician where Clinician_id = "+arg1+";");
    query.first();
    if(query.size() > 0)
    {
        ui->adminEditClinicianFName->setText(query.value("Clinician_firstname").toString());
        ui->adminEditClinicianLName->setText(query.value("Clinician_lastname").toString());
        ui->adminEditClinicianEmailName->setText(query.value("Clinician_Email").toString().split("@").at(0));
        ui->adminEditClinicianEmailServer->setText(query.value("Clinician_Email").toString().split("@").at(1).split(".").at(0));
    }
    else{
        ui->adminEditClinicianFName->setText("");
        ui->adminEditClinicianLName->setText("");
        ui->adminEditClinicianEmailName->setText("");
        ui->adminEditClinicianEmailServer->setText("");
    }
}

void MainWindow::on_adminEditDoctorID_valueChanged(const QString &arg1)
{
    QSqlQuery query(db);
    query.exec("select * from Doctor where Doctor_id = "+arg1+";");
    query.first();
    if(query.size() > 0)
    {
        ui->adminEditDoctorFName->setText(query.value("Doctor_firstname").toString());
        ui->adminEditDoctorLName->setText(query.value("Doctor_lastname").toString());
        ui->adminEditDoctorEmailName->setText(query.value("Doctor_Email").toString().split("@").at(0));
        ui->adminEditDoctorEmailServer->setText(query.value("Doctor_Email").toString().split("@").at(1).split(".").at(0));
        ui->adminEditDoctorDepartment->setCurrentText(query.value("Doctor_department").toString());
    }
    else{
        ui->adminEditDoctorFName->setText("");
        ui->adminEditDoctorLName->setText("");
        ui->adminEditDoctorEmailName->setText("");
        ui->adminEditDoctorEmailServer->setText("");
        ui->adminEditDoctorDepartment->setCurrentIndex(0);
    }
}

void MainWindow::on_adminDoctorSearch_textChanged(const QString &arg1)
{
    drawTable("select doctor_id as 'ID',doctor_firstname as 'First Name',doctor_lastName as 'Last Name',doctor_Email as 'E-Mail',doctor_department as 'Department' from Doctor where doctor_firstName like '%"+arg1+"%' OR doctor_lastName like '%"+arg1+"%' OR Doctor_department like '%"+arg1+"%' OR Doctor_email like '%"+arg1+"%';",ui->adminDoctorTable);
}

void MainWindow::on_adminClinicianSearch_textChanged(const QString &arg1)
{
    drawTable("select clinician_id as 'ID',clinician_firstname as 'First Name',clinician_lastName as 'Last Name',clinician_Email as 'E-Mail' from clinician where clinician_firstName like '%"+arg1+"%' OR clinician_lastName like '%"+arg1+"%' OR clinician_email like '%"+arg1+"%';",ui->adminClinicianTable);
}

void MainWindow::on_adminStudentSearch_textChanged(const QString &arg1)
{
    drawTable("select student_id as 'ID',student_firstname as 'First Name',student_lastName as 'Last Name',student_Email as 'E-Mail' from Student where student_firstName like '%"+arg1+"%' OR student_lastName like '%"+arg1+"%' OR student_email like '%"+arg1+"%';",ui->adminStudentTable);
}

void MainWindow::on_adminToolBoxCollapse_clicked()
{
    if(ui->adminToolbox->isHidden())
    {ui->adminToolbox->setHidden(false);}
    else
    {ui->adminToolbox->setHidden(true);}
}

void MainWindow::on_clinicianGenerateQueue_clicked()
{
    if(ui->clinicianGenerateQueueDoctor->currentText() == "==Select Doctor==")
    {
        Blink(ui->clinicianGenerateQueueDoctor);
        return;
    }
    QSqlQuery query(db);
    query.exec("select queue_code from queue where queue_for_doctor = (select doctor_id from doctor where doctor_firstname = '"+ui->clinicianGenerateQueueDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->clinicianGenerateQueueDoctor->currentText().split(" ").at(1)+"');");
    if(query.size()>0)
    {
        query.first();
        QMessageBox::warning(this,"Operation Failed","A Queue already exists for this doctor!\nQueue Code: "+query.value(0).toString());
        return;
    }
    query.exec("insert into queue(queue_for_doctor)values((select doctor_id from doctor where doctor_firstname = '"+ui->clinicianGenerateQueueDoctor->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->clinicianGenerateQueueDoctor->currentText().split(" ").at(1)+"'));");
    query.exec("select max(queue_code) from queue;");
    query.first();
    ui->clinicianGenerateQueueCode->setText("Last Queue Code: "+query.value(0).toString());
    refreshContent();
}

void MainWindow::on_clinicianDeleteQueue_clicked()
{
    QSqlQuery query(db);
    query.exec("delete from queue_content where queue_code = "+ui->clinicianDeleteQueueCode->currentText()+";");
    query.exec("delete from queue where queue_code = "+ui->clinicianDeleteQueueCode->currentText()+";");
    refreshContent();

}

void MainWindow::on_clinicianViewQueue_clicked()
{
    QSqlQuery query(db);
    query.exec("select concat(student_firstname,' ',student_lastname) as res from queue_content as q join student as s on q.student_id = s.student_id where queue_code = "+ui->clinicianDeleteQueueCode->currentText()+" order by(entered_queue_at);");
    query.first();
    if(query.size() > 0)
    {
        ui->clinicianQueueCurrentPatient->setText("Current Patient: "+ query.value(0).toString());
    }
    else{
        ui->clinicianQueueCurrentPatient->setText("Current Patient: N/A");
    }
    ui->clinicianQueueFrameCode->setText("Queue Code " + ui->clinicianDeleteQueueCode->currentText());
    drawTable("select concat(student_firstname,' ',student_lastname) as Patient,entered_queue_at as 'Arrived At' from queue_content as q join student as s on q.student_id = s.student_id where queue_code = "+ui->clinicianDeleteQueueCode->currentText()+" order by(entered_queue_at);",ui->clinicianQueueTable);

    /************GUI Code***********************/
    on_clinicianToolboxCollapse_clicked();
    ui->clinicianToolboxCollapse->setHidden(false);
    ui->clinicianQueueFrame->setHidden(false);
    /******************************************/
}

void MainWindow::on_clinicianRemovePatientFromQueue_clicked()
{
    QSqlQuery query(db);
    QString QueueCode = ui->clinicianQueueFrameCode->text().split(" ").at(2);
    query.exec("select student_id from queue_content where queue_code = "+QueueCode+" order by(entered_queue_at);");
    query.first();
    if(query.size() < 0)
    {
        return;
    }
    QString id = query.value(0).toString();
    query.exec("delete from queue_content where queue_code = "+QueueCode+" and student_id = "+id+";");
    on_clinicianViewQueue_clicked();
    qDebug() << query.lastQuery();
}

void MainWindow::on_clinicianPendingAppointmentApprove_clicked()
{
    QSqlQuery query(db);
    query.exec("update appointment set appointment_status = 'Approved' where appointment_id = "+ui->clinicianPendingAppointmentID->text()+";");
    query.exec("insert into student_notification values((select student_id from appointment where appointment_id = "+ui->clinicianPendingAppointmentID->text()+"),'Your Appointment Has Been Approved Please Check Your Portal!')");
    QMessageBox::information(this,"Operation Successful","Appointment Confirmed!\nAutomated Notification Sent!");
    refreshContent();
}

void MainWindow::on_clinicianPendingAppointmentReject_clicked()
{
    QSqlQuery query(db);
    query.exec("insert into student_notification values((select student_id from appointment where appointment_id = "+ui->clinicianPendingAppointmentID->text()+"),'Your Appointment Has Been Rejected Please Contact The Clinic!')");
    query.exec("delete from appointment where appointment_id = "+ui->clinicianPendingAppointmentID->text()+";");

    QMessageBox::information(this,"Operation Successful","Appointment Rejected!\nAutomated Notification Sent!");
    refreshContent();
}

void MainWindow::on_clinicianUpcomingAppointmentSearch_textChanged(const QString &arg1)
{
    QSqlQuery query(db);
    QWidget *widget = new QWidget();
    ui->clinicianUpcomingAppointmentList->widget()->deleteLater();
    ui->clinicianUpcomingAppointmentList->setWidget( widget );

    QVBoxLayout *layout = new QVBoxLayout();
    widget->setLayout( layout );

    query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.appointment_date between curdate() and date_add(curdate(),interval 7 day) and (s.student_firstname like '%"+arg1+"%' OR s.student_lastname like '%"+arg1+"%' OR d.doctor_firstname like '%"+arg1+"%' OR d.doctor_lastname like '%"+arg1+"%' OR s.student_email like '%"+arg1+"%' OR d.doctor_email like '%"+arg1+"%') order by (a.appointment_date);");
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString( "Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//appointment data
        connect(button,SIGNAL(clicked()),this,SLOT(upcomingAppointmentButtonClick()));
        layout->addWidget( button );
        query.next();
    }
}

void MainWindow::on_clinicianPendingAppointmentSearch_textChanged(const QString &arg1)
{
    QSqlQuery query(db);
    QWidget *widget2 = new QWidget();
    ui->clinicianPendingAppointmentList->widget()->deleteLater();
    ui->clinicianPendingAppointmentList->setWidget( widget2 );

    QVBoxLayout *layout2 = new QVBoxLayout();
    widget2->setLayout( layout2 );
    query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Pending' and (s.student_firstname like '%"+arg1+"%' OR s.student_lastname like '%"+arg1+"%' OR d.doctor_firstname like '%"+arg1+"%' OR d.doctor_lastname like '%"+arg1+"%' OR s.student_email like '%"+arg1+"%' OR d.doctor_email like '%"+arg1+"%') order by (a.appointment_date);");
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString( "Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );
        connect(button,SIGNAL(clicked()),this,SLOT(pendingAppointmentButtonClick()));
        layout2->addWidget( button );
        query.next();
    }
}

void MainWindow::on_doctorLogin_clicked()
{
    ui->doctorLoginWarning->setText("");

    QSqlQuery query(db);
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
    hash->addData(ui->doctorLoginPassword->text().toUtf8());
    query.exec("select * from doctor where doctor_id = "+ui->doctorLoginID->text()+";");
    if(query.size() == 1)
    {
        query.first();
        if(query.value("doctor_password").toString() == hash->result().toHex())
        {

            ui->mainStack->setCurrentIndex(4);
            ui->doctorStack->setCurrentIndex(0);
            on_doctorToolboxCollapse_clicked();

            //refreshContent();
            //resizeEvent(new QResizeEvent(size(),size()));

        }
        else{
            ui->doctorLoginWarning->setText("Invalid Password");
            Blink(ui->doctorLoginPassword);
        }
    }
    else {
        ui->doctorLoginWarning->setText("Invalid UserName");
        Blink(ui->doctorLoginID);
    }

}

void MainWindow::on_doctorLogout_clicked()
{
    ui->doctorLoginID->setValue(0);
    ui->doctorLoginPassword->setText("");
    ui->doctorLoginWarning->setText("");
    ui->mainStack->setCurrentIndex(0);
}

void MainWindow::on_doctorAppointmentView_activated(const QString &arg1)
{
    /****************Doctor Appointments*****************/

    QSqlQuery query(db);
    QWidget *widget3 = new QWidget();
    ui->doctorAppointments->widget()->deleteLater();
    ui->doctorAppointments->setWidget( widget3 );

    QVBoxLayout *layout3 = new QVBoxLayout();
    widget3->setLayout( layout3 );
    if(arg1 == "ALL"){
        query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.doctor_id = "+ui->doctorLoginID->text()+" order by (a.appointment_date);");
    }
    else if(arg1 == "TODAY")
    {
        query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.doctor_id = "+ui->doctorLoginID->text()+" and a.appointment_date = curdate() order by (a.appointment_date);");
    }
    else if(arg1 == "UPCOMING")
    {
        query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.doctor_id = "+ui->doctorLoginID->text()+" and a.appointment_date > curdate() order by (a.appointment_date);");
    }
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString("Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//dummy appointment data
        layout3->addWidget( button );
        query.next();
    }
}

void MainWindow::on_doctorQuestionnaire_clicked()
{
    /***************GUI Code****************/
    ui->doctorSettingFrame->setHidden(true);
    ui->doctorToolboxCollapse->setHidden(false);
    ui->doctorQuestionnaireFrame->setHidden(false);

    /*****************************************/

    QSqlQuery query(db);
    query.exec("select questionnaire_question_id,questionnaire_question from questionnaire_question where questionnaire_id = (select questionnaire_id from questionnaire where questionnaire_doctor = "+ui->doctorLoginID->text()+") order by (questionnaire_question_id);");
    ui->doctorQuestionnaireSelectQuestion->clear();
    for (int i = 0;i < query.size();i++) {
        ui->doctorQuestionnaireSelectQuestion->addItem(QString("%1").arg(i+1));
    }
    if(query.size()>0)
    {
        query.first();
        ui->doctorQuestionnaireQuestion->setText(query.value(1).toString());
        query.exec("select questionnaire_option from questionnaire_options where questionnaire_question_id = "+query.value(0).toString()+" order by questionnaire_option_id");
        query.first();
        ui->doctorQuestionnaireOptionA->setText(query.value(0).toString());
        query.next();
        ui->doctorQuestionnaireOptionB->setText(query.value(0).toString());
        query.next();
        ui->doctorQuestionnaireOptionC->setText(query.value(0).toString());
        query.next();
        ui->doctorQuestionnaireOptionD->setText(query.value(0).toString());
        query.next();
    }
    else{
        ui->doctorQuestionnaireQuestion->setText("");
        ui->doctorQuestionnaireOptionA->setText("");
        ui->doctorQuestionnaireOptionB->setText("");
        ui->doctorQuestionnaireOptionC->setText("");
        ui->doctorQuestionnaireOptionD->setText("");
    }


}

void MainWindow::on_doctorQuestionnaireAddQuestion_clicked()
{
    QSqlQuery query(db);
    query.exec("select questionnaire_id from questionnaire where questionnaire_doctor = "+ui->doctorLoginID->text()+";"); //checking if a Questionnaire exists for doctor or not
    if(query.size()>0)//if Questionnaire exists
    {
        query.first();
        QString id = query.value(0).toString();

        query.exec("insert into questionnaire_question(questionnaire_id,questionnaire_question)values("+id+",'What Is Your Question?');");//inserting questionnaire question
        query.exec("select max(questionnaire_question_id) from questionnaire_question;");//getting question id
        query.first();
        id = query.value(0).toString();

        for(int i = 1; i<5;i++)
        {
            query.exec("insert into questionnaire_options(questionnaire_question_id,questionnaire_option)values("+id+",'Type Your Option!');");//inserting question options
        }
        on_doctorQuestionnaire_clicked();//just to refresh the section
        QMessageBox::information(this,"Operation Successful","New Question Added Successfully!");
        ui->doctorQuestionnaireSelectQuestion->setCurrentIndex(ui->doctorQuestionnaireSelectQuestion->count()-1);
    }
    else{
        query.exec("insert into questionnaire(questionnaire_doctor)values("+ui->doctorLoginID->text()+");");//inserting questionnaire for the doctor
        on_doctorQuestionnaireAddQuestion_clicked();//recursion to run the above if section
    }
}

void MainWindow::on_doctorQuestionnaireDeleteQuestion_clicked()
{
    if(ui->doctorQuestionnaireSelectQuestion->currentText() == "")
    {
        Blink(ui->doctorQuestionnaireSelectQuestion);
        return;
    }
    if(QMessageBox::question(this,"Confirmation","Are You Sure You Want To Delete This Question?\nIt will also remove the submissions, submitted by the patients against this Question.") == QMessageBox::No)
    {
        return;
    }
    QSqlQuery query(db);
    query.exec("select questionnaire_id from questionnaire where questionnaire_doctor = "+ui->doctorLoginID->text()+";");
    query.first();
    QString id = query.value(0).toString();
    query.exec("select questionnaire_question_id from questionnaire_question where questionnaire_id = "+id+" order by(questionnaire_question_id);");
    query.first();
    query.seek(ui->doctorQuestionnaireSelectQuestion->currentText().toInt() - 1);
    id = query.value(0).toString();
    query.exec("delete from questionnaire_submissions where questionnaire_question_id = "+id+";");
    query.exec("delete from questionnaire_options where questionnaire_question_id = "+id+";");
    query.exec("delete from questionnaire_question where questionnaire_question_id = "+id+";");
    on_doctorQuestionnaire_clicked();
    QMessageBox::information(this,"Operation Successful","Question Deleted Successfully!");

}

void MainWindow::on_doctorQuestionnaireSubmit_clicked()
{
    if(QMessageBox::question(this,"Confirmation","Are You Sure?\nModifying A Question Will Remove All Previous Submissions Against It!\n") == QMessageBox::Yes)
    {
        QSqlQuery query(db);
        query.exec("select questionnaire_id from questionnaire where questionnaire_doctor = "+ui->doctorLoginID->text()+";");
        query.first();
        QString id = query.value(0).toString();
        query.exec("select questionnaire_question_id from questionnaire_question where questionnaire_id = "+id+" order by(questionnaire_question_id);");
        query.first();
        query.seek(ui->doctorQuestionnaireSelectQuestion->currentText().toInt() - 1);
        id = query.value(0).toString();
        query.exec("update questionnaire_question set questionnaire_question = '"+ui->doctorQuestionnaireQuestion->toPlainText()+"' where questionnaire_question_id = "+id+";");
        query.exec("delete from questionnaire_options where questionnaire_question_id = "+id+";");
        query.exec("insert into questionnaire_options(questionnaire_question_id,questionnaire_option)values("+id+",'"+ui->doctorQuestionnaireOptionA->text()+"')");
        query.exec("insert into questionnaire_options(questionnaire_question_id,questionnaire_option)values("+id+",'"+ui->doctorQuestionnaireOptionB->text()+"')");
        query.exec("insert into questionnaire_options(questionnaire_question_id,questionnaire_option)values("+id+",'"+ui->doctorQuestionnaireOptionC->text()+"')");
        query.exec("insert into questionnaire_options(questionnaire_question_id,questionnaire_option)values("+id+",'"+ui->doctorQuestionnaireOptionD->text()+"')");
        QMessageBox::information(this,"Operation Successfull","Question Updated Successfully");
        on_doctorQuestionnaire_clicked();
    }

}

void MainWindow::on_doctorQuestionnaireSelectQuestion_activated(const QString &arg1)
{
    if(arg1 == ""){
        return;
    }
    QSqlQuery query(db);
    query.exec("select questionnaire_id from questionnaire where questionnaire_doctor = "+ui->doctorLoginID->text()+";");
    query.first();
    QString id = query.value(0).toString();
    query.exec("select questionnaire_question_id from questionnaire_question where questionnaire_id = "+id+" order by(questionnaire_question_id);");
    query.first();
    query.seek(arg1.toInt() - 1);
    id = query.value(0).toString();

    query.exec("select questionnaire_question from questionnaire_question where questionnaire_question_id = "+id+";");
    query.first();
    ui->doctorQuestionnaireQuestion->setText(query.value(0).toString());
    query.exec("select questionnaire_option from questionnaire_options where questionnaire_question_id = "+id+" order by questionnaire_option_id");
    query.first();
    ui->doctorQuestionnaireOptionA->setText(query.value(0).toString());
    query.next();
    ui->doctorQuestionnaireOptionB->setText(query.value(0).toString());
    query.next();
    ui->doctorQuestionnaireOptionC->setText(query.value(0).toString());
    query.next();
    ui->doctorQuestionnaireOptionD->setText(query.value(0).toString());
    query.next();

}

void MainWindow::on_doctorToolboxCollapse_clicked()
{
    ui->doctorQuestionnaireFrame->setHidden(true);
    ui->doctorSettingFrame->setHidden(true);
    ui->doctorToolboxCollapse->setHidden(true);
    ui->doctorSettingChangeEmailFrame->setHidden(true);
    ui->doctorSettingChangePasswordFrame->setHidden(true);
}

void MainWindow::on_doctorSettings_clicked()
{
    /*****************GUI CODE**********************/

    on_doctorToolboxCollapse_clicked();
    ui->doctorSettingFrame->setHidden(false);
    ui->doctorToolboxCollapse->setHidden(false);
    /**********************************************/

    QSqlQuery query(db);
    query.exec("select concat(doctor_firstname,' ',doctor_lastname),doctor_email,doctor_department from doctor where doctor_id = "+ui->doctorLoginID->text()+";");
    query.first();
    ui->doctorSettingName->setText("Name: Dr."+query.value(0).toString());
    ui->doctorSettingEmail->setText("Email: "+query.value(1).toString());
    ui->doctorSettingDepartment->setText("Department: "+query.value(2).toString());
    ui->doctorSettingChangeEmailUser->setText("");
    ui->doctorSettingChangeEmailServer->setText("");
    ui->doctorSettingChangePasswordOldPass->setText("");
    ui->doctorSettingChangePasswordNewPass->setText("");
    ui->doctorSettingChangePasswordConfirmPass->setText("");
}
void MainWindow::on_doctorSettingChangeEmail_clicked()
{
    if(ui->doctorSettingChangeEmailFrame->isHidden())
    {
        ui->doctorSettingChangeEmailFrame->setHidden(false);
    }
    else{
        ui->doctorSettingChangeEmailFrame->setHidden(true);
    }
}

void MainWindow::on_doctorSettingChangePassword_clicked()
{
    if(ui->doctorSettingChangePasswordFrame->isHidden())
    {
        ui->doctorSettingChangePasswordFrame->setHidden(false);
    }
    else{
        ui->doctorSettingChangePasswordFrame->setHidden(true);
    }
}

void MainWindow::on_doctoerSettingChangeEmailSubmit_clicked()
{
    if(ui->doctorSettingChangeEmailUser->text() == "" && ui->doctorSettingChangeEmailServer->text() == "")
    {
        Blink(ui->doctorSettingChangeEmailUser);
        Blink(ui->doctorSettingChangeEmailServer);
        return;
    }
    QSqlQuery query(db);
    query.exec("update doctor set doctor_email = '"+ui->doctorSettingChangeEmailUser->text()+"@"+ui->doctorSettingChangeEmailServer->text()+".com"+"' where doctor_id = "+ui->doctorLoginID->text()+";");
    QMessageBox::information(this,"Operation Successfull","Email Changed Successfully!");
    on_doctorSettings_clicked();

}

void MainWindow::on_doctorSettingChangePasswordSubmit_clicked()
{
    if(ui->doctorLoginPassword->text() == ui->doctorSettingChangePasswordOldPass->text())
    {
        if(ui->doctorSettingChangePasswordNewPass->text() == ui->doctorSettingChangePasswordConfirmPass->text())
        {
            QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
            hash->addData(ui->doctorSettingChangePasswordNewPass->text().toUtf8());
            QSqlQuery query(db);
            query.exec("update doctor set doctor_password = '"+hash->result().toHex()+"' where doctor_id = "+ui->doctorLoginID->text()+";");
            QMessageBox::information(this,"Operation Successful","Password Changed Successfully!");
            on_doctorSettings_clicked();

        }
        else
        {
            Blink(ui->doctorSettingChangePasswordNewPass);
            Blink(ui->doctorSettingChangePasswordConfirmPass);
        }
    }
    else
    {
        Blink(ui->doctorSettingChangePasswordOldPass);
        return;
    }
}

void MainWindow::on_doctorMessageBox_clicked()
{
     ui->doctorStack->setCurrentIndex(1);
     ui->doctorMessageNewFrame->setHidden(true);
     QSqlQuery query(db);
     query.exec("select concat(student_firstname,' ',student_lastname) from student;");
     query.first();
     ui->doctorMessageSendTo->clear();
     for(int i = 0;i<query.size();i++)
     {
         ui->doctorMessageSendTo->addItem(query.value(0).toString());
         query.next();
     }
     ui->doctorMessageBody->setText("");
     /********************inbox***************************/

     query.exec("select concat(student_firstname,' ',student_lastname),message_timestamp,message from message_inbox_doctor as m join student as s on m.student_id = s.student_id where m.doctor_id = "+ui->doctorLoginID->text()+" order by (m.message_timestamp);");
     query.first();
     ui->doctorMessageInbox->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
     ui->doctorMessageInbox->setWidgetResizable( true );

     QWidget *widget3 = new QWidget();
     ui->doctorMessageInbox->setWidget( widget3 );

     QVBoxLayout *layout3 = new QVBoxLayout();
     widget3->setLayout( layout3 );
     for (int i = 0; i < query.size(); i++)
     {
         QPushButton *button = new QPushButton( QString("From: %1 \nTime: %2\n\nMessage Body:\n\n %3" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()) );//dummy appointment data
         layout3->addWidget( button );
         query.next();
     }
     /**********************Outbox************************/
     query.exec("select concat(student_firstname,' ',student_lastname),message_timestamp,message from message_inbox_student as m join student as s on m.student_id = s.student_id where m.doctor_id = "+ui->doctorLoginID->text()+" order by (m.message_timestamp);");
     query.first();
     ui->doctorMessageOutbox->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
     ui->doctorMessageOutbox->setWidgetResizable( true );

     QWidget *widget = new QWidget();
     ui->doctorMessageOutbox->setWidget( widget );

     QVBoxLayout *layout = new QVBoxLayout();
     widget->setLayout( layout );
     for (int i = 0; i < query.size(); i++)
     {
         QPushButton *button = new QPushButton( QString("To: %1 \nTime: %2\n\nMessage Body:\n\n %3" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()) );//dummy appointment data
         layout->addWidget( button );
         query.next();
     }
}

void MainWindow::on_doctorMessageNewButton_clicked()
{
    if(ui->doctorMessageNewFrame->isHidden())
    {
        ui->doctorMessageNewFrame->setHidden(false);
        ui->doctorMessageExit->setHidden(true);
    }
    else
    {
        ui->doctorMessageNewFrame->setHidden(true);
        ui->doctorMessageExit->setHidden(false);
    }
}

void MainWindow::on_doctorMessageSend_clicked()
{
    if(ui->doctorMessageBody->toPlainText() == "")
    {
        Blink(ui->doctorMessageBody);
        return;
    }
    if(ui->doctorMessageSendTo->currentText() == "")
    {
        Blink(ui->doctorMessageSendTo);
        return;
    }
    QSqlQuery query(db);
    query.exec("insert into message_inbox_student(doctor_id,student_id,message)values("+ui->doctorLoginID->text()+",(select student_id from student where student_firstname = '"+ui->doctorMessageSendTo->currentText().split(" ").at(0)+"' and student_lastname = '"+ui->doctorMessageSendTo->currentText().split(" ").at(1)+"'),'"+ui->doctorMessageBody->toPlainText()+"')");
    QMessageBox::information(this,"Message Sent","Message Delivered Successfully!");
    on_doctorMessageBox_clicked();
}

void MainWindow::on_doctorMessageExit_clicked()
{
    ui->doctorStack->setCurrentIndex(0);
}

void MainWindow::on_studentQuestionnaireNext_clicked()
{
    if(ui->studentQuestionnaireStack->currentIndex() == ui->studentQuestionnaireStack->count())
    {
        return;
    }
    ui->studentQuestionnaireStack->setCurrentIndex(ui->studentQuestionnaireStack->currentIndex()+1);
    ui->studentQuestionnaireProgress->setValue( static_cast<int>(((ui->studentQuestionnaireStack->currentIndex()+1)*100) / ui->studentQuestionnaireStack->count()));

}

void MainWindow::on_studentQuestionnairePrev_clicked()
{
    if(ui->studentQuestionnaireStack->currentIndex() == 0)
    {
        return;
    }
    ui->studentQuestionnaireStack->setCurrentIndex(ui->studentQuestionnaireStack->currentIndex()-1);

    ui->studentQuestionnaireProgress->setValue(static_cast<int>(((ui->studentQuestionnaireStack->currentIndex()+1)*100) / ui->studentQuestionnaireStack->count()) );
}

void MainWindow::on_doctorQuestionnaireViewSubmissions_clicked()
{
    ui->doctorStack->setCurrentIndex(2);
    QSqlQuery query(db);
    query.exec("select distinct concat(student_firstname,' ',student_lastname),qs.student_id from questionnaire_submissions as qs join student as s on qs.student_id = s.student_id join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join questionnaire as q on q.questionnaire_id = qq.questionnaire_id where q.questionnaire_doctor = "+ui->doctorLoginID->text()+" order by(s.student_firstname);");
    query.first();
    QString id = query.value(1).toString();//id of the first student in the combobox
    ui->doctorQuestionnaireSubmissionStudent->clear();
    for (int i = 0; i< query.size();i++) {
        ui->doctorQuestionnaireSubmissionStudent->addItem(query.value(0).toString());
        query.next();
    }

    QWidget *widget2 = new QWidget();
    ui->doctorQuestionnaireSubmissions->setWidget( widget2 );

    QVBoxLayout *layout2 = new QVBoxLayout();
    widget2->setLayout( layout2 );
    query.exec("select questionnaire_question,qo.questionnaire_option from questionnaire_submissions as qs join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join student as s on qs.student_id = s.student_id join questionnaire_options as qo on qs.questionnaire_option_id = qo.questionnaire_option_id join questionnaire as q on q.questionnaire_id = qq.questionnaire_id where q.questionnaire_doctor = "+ui->doctorLoginID->text()+" and s.student_id = "+id+";");
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QLabel *sub = new QLabel( QString( "Question:   %1\nAnswer:     %2" ).arg(query.value(0).toString()).arg(query.value(1).toString()));
        const QFont *font = new QFont("Impact",20);
        sub->setFont(*font);
        layout2->addWidget( sub );
        query.next();
    }

}

void MainWindow::on_doctorQuestionnaireSubmissionExit_clicked()
{
    ui->doctorStack->setCurrentIndex(0);
}

void MainWindow::on_doctorQuestionnaireSubmissionStudent_activated(const QString &arg1)
{
    if(arg1 == "")
    {
        return;
    }
    QSqlQuery query(db);
    QWidget *widget2 = new QWidget();
    ui->doctorQuestionnaireSubmissions->setWidget( widget2 );

    QVBoxLayout *layout2 = new QVBoxLayout();
    widget2->setLayout( layout2 );
    query.exec("select questionnaire_question,qo.questionnaire_option from questionnaire_submissions as qs join questionnaire_question as qq on qs.questionnaire_question_id = qq.questionnaire_question_id join student as s on qs.student_id = s.student_id join questionnaire_options as qo on qs.questionnaire_option_id = qo.questionnaire_option_id join questionnaire as q on q.questionnaire_id = qq.questionnaire_id where q.questionnaire_doctor = "+ui->doctorLoginID->text()+" and s.student_firstname = '"+arg1.split(" ").at(0)+"' and s.student_lastname = '"+arg1.split(" ").at(1)+"';");
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QLabel *sub = new QLabel( QString( "Question:   %1\nAnswer:     %2" ).arg(query.value(0).toString()).arg(query.value(1).toString()));
        const QFont *font = new QFont("Impact",20);
        sub->setFont(*font);
        layout2->addWidget( sub );
        query.next();
    }
}

void MainWindow::on_studentSettings_clicked()
{
    QSqlQuery query(db);
    query.exec("select concat(student_firstname,' ',student_lastname),student_email from student where student_id = "+ui->studentLoginID->text()+";");
    query.first();
    ui->studentSettingName->setText("Name: "+query.value(0).toString());
    ui->studentSettingEmail->setText("Email: "+query.value(1).toString());
    ui->studentSettingChangeEmailUser->setText("");
    ui->studentSettingChangeEmailServer->setText("");
    ui->studentSettingChangePasswordOldPass->setText("");
    ui->studentSettingChangePasswordNewPass->setText("");
    ui->studentSettingChangePasswordConfirmPass->setText("");

    /*******************GUI Code*****************/
    on_studentToolboxCollapse_clicked();
    ui->studentToolboxCollapse->setHidden(false);
    ui->studentSettingFrame->setHidden(false);
    /********************************************/
}

void MainWindow::on_studentSettingChangeEmail_clicked()
{
    if(ui->studentSettingChangeEmailFrame->isHidden())
    {
        ui->studentSettingChangeEmailFrame->setHidden(false);
    }
    else{
        ui->studentSettingChangeEmailFrame->setHidden(true);
    }
}



void MainWindow::on_studentSettingChangePassword_clicked()
{
    if(ui->studentSettingChangePasswordFrame->isHidden())
    {
        ui->studentSettingChangePasswordFrame->setHidden(false);
    }
    else{
        ui->studentSettingChangePasswordFrame->setHidden(true);
    }
}

void MainWindow::on_studentSettingChangeEmailSubmit_clicked()
{
    if(ui->studentSettingChangeEmailUser->text() == "" && ui->studentSettingChangeEmailServer->text() == "")
    {
        Blink(ui->studentSettingChangeEmailUser);
        Blink(ui->studentSettingChangeEmailServer);
        return;
    }
    QSqlQuery query(db);
    query.exec("update student set student_email = '"+ui->studentSettingChangeEmailUser->text()+"@"+ui->studentSettingChangeEmailServer->text()+".com"+"' where student_id = "+ui->studentLoginID->text()+";");
    QMessageBox::information(this,"Operation Successfull","Email Changed Successfully!");
    on_studentSettings_clicked();
}

void MainWindow::on_studentSettingChangePasswordSubmit_clicked()
{
    if(ui->studentLoginPassword->text() == ui->studentSettingChangePasswordOldPass->text())
    {
        if(ui->studentSettingChangePasswordNewPass->text() == ui->studentSettingChangePasswordConfirmPass->text())
        {
            QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
            hash->addData(ui->studentSettingChangePasswordNewPass->text().toUtf8());
            QSqlQuery query(db);
            query.exec("update student set student_password = '"+hash->result().toHex()+"' where student_id = "+ui->studentLoginID->text()+";");
            QMessageBox::information(this,"Operation Successful","Password Changed Successfully!");
            on_studentSettings_clicked();

        }
        else
        {
            Blink(ui->studentSettingChangePasswordNewPass);
            Blink(ui->studentSettingChangePasswordConfirmPass);
        }
    }
    else
    {
        Blink(ui->studentSettingChangePasswordOldPass);
        return;
    }
}

void MainWindow::on_studentMessageBox_clicked()
{
    ui->studentStack->setCurrentIndex(2);
    ui->studentMessageNewFrame->setHidden(true);
    QSqlQuery query(db);
    query.exec("select concat(doctor_firstname,' ',doctor_lastname) from doctor;");
    query.first();
    ui->studentMessageSendTo->clear();
    for(int i = 0;i<query.size();i++)
    {
        ui->studentMessageSendTo->addItem(query.value(0).toString());
        query.next();
    }
    ui->studentMessageBody->setText("");
    /********************inbox***************************/

    query.exec("select concat(doctor_firstname,' ',doctor_lastname),message_timestamp,message from message_inbox_student as m join doctor as d on m.doctor_id = d.doctor_id where m.student_id = "+ui->studentLoginID->text()+" order by (m.message_timestamp);");
    query.first();
    ui->studentMessageInbox->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    ui->studentMessageInbox->setWidgetResizable( true );

    QWidget *widget3 = new QWidget();
    ui->studentMessageInbox->setWidget( widget3 );

    QVBoxLayout *layout3 = new QVBoxLayout();
    widget3->setLayout( layout3 );
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString("From: %1 \nTime: %2\n\nMessage Body:\n\n %3" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()) );//dummy appointment data
        layout3->addWidget( button );
        query.next();
    }
    /**********************Outbox************************/
    query.exec("select concat(doctor_firstname,' ',doctor_lastname),message_timestamp,message from message_inbox_doctor as m join doctor as d on m.doctor_id = d.doctor_id where m.student_id = "+ui->studentLoginID->text()+" order by (m.message_timestamp);");
    query.first();
    ui->studentMessageOutbox->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    ui->studentMessageOutbox->setWidgetResizable( true );

    QWidget *widget = new QWidget();
    ui->studentMessageOutbox->setWidget( widget );

    QVBoxLayout *layout = new QVBoxLayout();
    widget->setLayout( layout );
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString("To: %1 \nTime: %2\n\nMessage Body:\n\n %3" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()) );//dummy appointment data
        layout->addWidget( button );
        query.next();
    }
}

void MainWindow::on_studentMessageNewButton_clicked()
{
    if(ui->studentMessageNewFrame->isHidden())
    {
        ui->studentMessageNewFrame->setHidden(false);
        ui->studentMessageExit->setHidden(true);
    }
    else
    {
        ui->studentMessageNewFrame->setHidden(true);
        ui->studentMessageExit->setHidden(false);
    }
}

void MainWindow::on_studentMessageSend_clicked()
{
    if(ui->studentMessageBody->toPlainText() == "")
    {
        Blink(ui->studentMessageBody);
        return;
    }
    if(ui->studentMessageSendTo->currentText() == "")
    {
        Blink(ui->studentMessageSendTo);
        return;
    }
    QSqlQuery query(db);
    query.exec("insert into message_inbox_doctor(doctor_id,student_id,message)values((select doctor_id from doctor where doctor_firstname = '"+ui->studentMessageSendTo->currentText().split(" ").at(0)+"' and doctor_lastname = '"+ui->studentMessageSendTo->currentText().split(" ").at(1)+"'),"+ui->studentLoginID->text()+",'"+ui->studentMessageBody->toPlainText()+"')");
    QMessageBox::information(this,"Message Sent","Message Delivered Successfully!");
    on_studentMessageBox_clicked();
}

void MainWindow::on_studentMessageExit_clicked()
{
    ui->studentStack->setCurrentIndex(0);
}

void MainWindow::on_clinicianSetting_clicked()
{
    QSqlQuery query(db);
    query.exec("select concat(clinician_firstname,' ',clinician_lastname),clinician_email from clinician where clinician_id = "+ui->clinicianUsername->text()+";");
    query.first();
    ui->clinicianSettingName->setText("Name: "+query.value(0).toString());
    ui->clinicianSettingEmail->setText("Email: "+query.value(1).toString());
    ui->clinicianSettingChangeEmailUser->setText("");
    ui->clinicianSettingChangeEmailServer->setText("");
    ui->clinicianSettingChangePasswordOldPass->setText("");
    ui->clinicianSettingChangePasswordNewPass->setText("");
    ui->clinicianSettingChangePasswordConfirmPass->setText("");
    /*************GUI Code****************/
    on_clinicianToolboxCollapse_clicked();
    ui->clinicianToolboxCollapse->setHidden(false);
    ui->clinicianSettingFrame->setHidden(false);
    /**************************************/
}

void MainWindow::on_clinicianSettingChangeEmail_clicked()
{
    if(ui->clinicianSettingChangeEmailFrame->isHidden())
    {
        ui->clinicianSettingChangeEmailFrame->setHidden(false);
    }
    else{
        ui->clinicianSettingChangeEmailFrame->setHidden(true);
    }
}



void MainWindow::on_clinicianSettingChangePassword_clicked()
{
    if(ui->clinicianSettingChangePasswordFrame->isHidden())
    {
        ui->clinicianSettingChangePasswordFrame->setHidden(false);
    }
    else{
        ui->clinicianSettingChangePasswordFrame->setHidden(true);
    }
}

void MainWindow::on_clinicianSettingChangeEmailSubmit_clicked()
{
    if(ui->clinicianSettingChangeEmailUser->text() == "" && ui->clinicianSettingChangeEmailServer->text() == "")
    {
        Blink(ui->clinicianSettingChangeEmailUser);
        Blink(ui->clinicianSettingChangeEmailServer);
        return;
    }
    QSqlQuery query(db);
    query.exec("update clinician set clinician_email = '"+ui->clinicianSettingChangeEmailUser->text()+"@"+ui->clinicianSettingChangeEmailServer->text()+".com"+"' where clinician_id = "+ui->clinicianUsername->text()+";");
    QMessageBox::information(this,"Operation Successfull","Email Changed Successfully!");
    on_clinicianSetting_clicked();
}

void MainWindow::on_clinicianSettingChangePasswordSubmit_clicked()
{
    if(ui->clinicianPassword->text() == ui->clinicianSettingChangePasswordOldPass->text())
    {
        if(ui->clinicianSettingChangePasswordNewPass->text() == ui->clinicianSettingChangePasswordConfirmPass->text())
        {
            QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha3_256);
            hash->addData(ui->clinicianSettingChangePasswordNewPass->text().toUtf8());
            QSqlQuery query(db);
            query.exec("update clinician set clinician_password = '"+hash->result().toHex()+"' where clinician_id = "+ui->clinicianUsername->text()+";");
            QMessageBox::information(this,"Operation Successful","Password Changed Successfully!");
            on_clinicianSetting_clicked();

        }
        else
        {
            Blink(ui->clinicianSettingChangePasswordNewPass);
            Blink(ui->clinicianSettingChangePasswordConfirmPass);
        }
    }
    else
    {
        Blink(ui->clinicianSettingChangePasswordOldPass);
        return;
    }
}

void MainWindow::on_studentAppointmentSearch_textChanged(const QString &arg1)
{

    QWidget *widget3 = new QWidget();
    ui->studentAppointments->widget()->deleteLater();
    ui->studentAppointments->setWidget( widget3 );

    QVBoxLayout *layout3 = new QVBoxLayout();
    widget3->setLayout( layout3 );
    QSqlQuery query(db);
    query.exec("select appointment_id,concat(doctor_firstname,' ',doctor_lastname) as doct,concat(student_firstname,' ',student_lastname) as stud,appointment_date,appointment_time,appointment_pres_refill from appointment as a join student as s on a.student_id = s.student_id join doctor as d on a.doctor_id = d.doctor_id where a.appointment_status = 'Approved' and a.student_id = "+ui->studentLoginID->text()+" and (s.student_firstname like '%"+arg1+"%' OR s.student_lastname like '%"+arg1+"%' OR d.doctor_firstname like '%"+arg1+"%' OR d.doctor_lastname like '%"+arg1+"%') order by (a.appointment_date);");
    query.first();
    for (int i = 0; i < query.size(); i++)
    {
        QPushButton *button = new QPushButton( QString("Appointment: %1 \nDoctor Name: %2\nPatient Name: %3\nDate: %4\nTime: %5\nPrescription Refill: %6" ).arg( query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString()) );//dummy appointment data
        layout3->addWidget( button );
        query.next();
    }
}
