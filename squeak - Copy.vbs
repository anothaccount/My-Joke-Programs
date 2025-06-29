Dim i
Dim r
Dim shell
Set shell = CreateObject("WScript.Shell")

sqek=Msgbox("Can I sqweek a bawoon for you? :3",vbYesNo+32,"Hehe~")
Select Case sqek
Case vbYes
yay=Msgbox("SQUEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"Thank you!")
Case vbNo
plz=Msgbox("Pweeeeeease? OwO",vbYesNo+64,"Nya!")
Select Case plz
Case vbYes
yay=Msgbox("SQUEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"Thank you!")
Case vbNo
plz=Msgbox("Too bad! >:3",vbOKOnly+48,"Get weady!")
yay=Msgbox("SQUEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"Should've said yes!")
End Select
End Select