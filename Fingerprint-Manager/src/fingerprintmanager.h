#ifndef FINGERPRINTMANAGER_H
#define FINGERPRINTMANAGER_H

#include <QMainWindow>
#include <QSerialPort>

#include "dialogaddfinger.h"
#include "dialogsetopentime.h"

namespace Ui {
class FingerprintManager;
}

class FingerprintManager : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit FingerprintManager(QWidget *parent = 0);
	~FingerprintManager();
	
private slots:
	void on_pushButton_connect_clicked();
	void on_pushButton_update_clicked();
	void on_pushButton_addFinger_clicked();
	void on_pushButton_abort_clicked();
	void on_lineEdit_search_editingFinished();	
	
	void readSerial();
	void tableContextMenu(QPoint p);
	void deleteFinger();
	void setOpenTime();
	
public slots:
	
private:
	Ui::FingerprintManager *ui;
	
	QSerialPort *serial;
	DialogAddFinger *dialogAddFinger;
	DialogSetOpenTime *dialogSetOpenTime;
	
	int selectedID;
	
	
	void closeEvent(QCloseEvent *event);
	
	void parseListEntry(QString line);
};

#endif // FINGERPRINTMANAGER_H
