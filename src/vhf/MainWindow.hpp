// Copyright (c) 2016 Mario Konrad
// All Rights reserved.

#ifndef __RADIO_SIM__MAINWINDOW__HPP__
#define __RADIO_SIM__MAINWINDOW__HPP__

#include <QMainWindow>

class QTcpSocket;
class QAction;

namespace simradrd68
{
class Widget;
class GPSWindow;
class ControlCenter;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	virtual ~MainWindow();

protected:
	void closeEvent(QCloseEvent * event);

private slots:
	void on_about();
	void on_about_qt();
	void on_toggle_fullscreen(bool checked);
	void on_show_buttons(bool checked);
	void on_vhf_preferences();
	void on_connection_preferences();
	void on_connection_open();
	void on_connection_close();
	void on_controlcenter();
	void on_show_gps();
	void on_exam_mode(bool checked);

private:
	Widget * widget;
	GPSWindow * gps;
	ControlCenter * controlcenter;
	QTcpSocket * socket;
	QAction * action_open_connection;
	QAction * action_close_connection;
	QAction * action_control_center;

	void set_title();
	void connect_to_controlcenter();
	void socket_close();
	void handle_menu_entries();
};
}

#endif
