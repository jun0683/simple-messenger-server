#encoding:UTF-8

import socket

HOST = 'localhost'
PORT = 50000

class autoClient:

    def __init__(self):
		self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.login()
		self.logout()
		self.makeChattingRoom()
		self.inviteChattingRoom()
		self.leaveChattingRoom()

    def login(self):
		sendData = {}
		sendData['type'] = 1
		sendData['loginID'] = 'test@test.com'
		sendData['password'] = '1234'
		self.s.connect((HOST, PORT))
		self.s.sendall(str(sendData))
		data = self.s.recv(1024)
		print data
		print('login')

    def logout(self):
		self.s.close()
		print('logout')

    def makeChattingRoom(self):
        print('makeChattingRoom')

    def inviteChattingRoom(self):
        print('inviteChattingRoom')

    def leaveChattingRoom(self):
        print('leaveChattingRoom')