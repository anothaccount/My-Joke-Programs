Dim shell
Dim i
Set shell = CreateObject("WScript.Shell")
Set sapi=CreateObject("sapi.spvoice")
MsgBox("That's it i will open notepad and type you a scary message")
shell.Run "notepad.exe"
wscript.sleep 800
For i = 1 to 10
shell.sendkeys "O"
wscript.sleep 10
shell.sendkeys "h"
wscript.sleep 10
shell.sendkeys " "
wscript.sleep 50
Next
For i = 1 to 5
shell.sendkeys "~"
shell.sendkeys "H"
wscript.sleep 20
shell.sendkeys "o"
wscript.sleep 20
shell.sendkeys "w"
wscript.sleep 20
shell.sendkeys " "
wscript.sleep 20
shell.sendkeys "D"
wscript.sleep 20
shell.sendkeys "a"
wscript.sleep 20
shell.sendkeys "r"
wscript.sleep 20
shell.sendkeys "e"
wscript.sleep 20
shell.sendkeys " "
wscript.sleep 20
shell.sendkeys "Y"
wscript.sleep 20
shell.sendkeys "o"
wscript.sleep 20
shell.sendkeys "u"
wscript.sleep 20
Next
sapi.speak "I will now repeat this message"
shell.sendkeys "~"
For i = 1 to 10
shell.sendkeys "O"
wscript.sleep 10
shell.sendkeys "h"
wscript.sleep 10
shell.sendkeys " "
wscript.sleep 50
Next
For i = 1 to 5
shell.sendkeys "~"
shell.sendkeys "H"
wscript.sleep 20
shell.sendkeys "o"
wscript.sleep 20
shell.sendkeys "w"
wscript.sleep 20
shell.sendkeys " "
wscript.sleep 20
shell.sendkeys "D"
wscript.sleep 20
shell.sendkeys "a"
wscript.sleep 20
shell.sendkeys "r"
wscript.sleep 20
shell.sendkeys "e"
wscript.sleep 20
shell.sendkeys " "
wscript.sleep 20
shell.sendkeys "Y"
wscript.sleep 20
shell.sendkeys "o"
wscript.sleep 20
shell.sendkeys "u"
wscript.sleep 20
Next
shell.sendkeys "~"
shell.sendkeys "And if you didn't listen to my message..."
sapi.speak "And if you didn't listen to my message"
shell.sendkeys "~"
shell.sendkeys "Then too bad."
sapi.speak "Then too bad!"
wscript.sleep 500
For i = 1 to 100
shell.sendkeys "~"
wscript.sleep 1
shell.sendkeys "YOU'RE GONNA GET BEAT!"
wscript.sleep 1
Next
MsgBox("The end")
sapi.speak "That was my message. Now goodbye!"