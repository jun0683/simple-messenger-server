#encoding:UTF-8

import socket
import struct
import json

HOST = 'localhost'
PORT = 50000

class autoClient:

	def __init__(self):
		self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.login()
		#self.logout()
		self.makeChattingRoom()
		self.inviteChattingRoom()
		self.leaveChattingRoom()

	def recvPacket(self):
		length = self.readHead()
		return self.readBody(length)

	def readHead(self):
		data = self.s.recv(4)
		return struct.unpack("I",data)[0]
		
	def readBody(self,length):
		data = self.s.recv(length)
		return json.loads(data.decode('utf-8'))

	def makeLoginPacket(self):
		sendData = {}
		sendData["type"] = 1
		sendData["loginID"] = "test1@test.com"
		sendData["password"] = "1234"
		sendData["message"] = "하이"
		length = struct.pack("I", len(json.dumps(sendData)))
		return length+json.dumps(sendData)

	def login(self):
		
		self.s.connect((HOST, PORT))
		self.s.sendall(self.makeLoginPacket())
		recvjson = self.recvPacket()
		print recvjson['name']
		print recvjson['userID']

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