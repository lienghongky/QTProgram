# -*- coding: utf-8 -*-

try:
    from PySide import QtCore
    from PySide import QtWidgets
except:
    from PyQt5.QtCore import pyqtSlot as Slot
    from PyQt5 import QtCore
    from PyQt5 import QtWidgets
import sys
from PyQt5 import QtGui


class MainUIWindown(QtGui.QMainWindow):
    def __init__(self):
        super(MainUIWindown,self).__init__()
        loadUi("mainwindowm",self)

app = QApplication(sys.argv)

