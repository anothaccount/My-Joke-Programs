Dim i
Dim r
Dim shell
Set shell = CreateObject("WScript.Shell")

sqek=Msgbox("Prepare for the cutest sqweek ever! x3",vbYesNo+64,"Hehe~")
Select Case sqek
Case vbYes
yay=Msgbox("SQUEEEEEEEEEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"SO CUTE!")
Case vbNo
plz=Msgbox("Pweeeeeease? OwO",vbYesNo+64,"Nya!")
Select Case plz
Case vbYes
yay=Msgbox("SQUEEEEEEEEEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"SO CUTE!")
Case vbNo
plz=Msgbox("Too bad! >:3",vbOKOnly+48,"Get weady!")
plz=Msgbox("3..",vbOKOnly+48,"Get weady!")
plz=Msgbox("2..",vbOKOnly+48,"Get weady!")
plz=Msgbox("1..",vbOKOnly+48,"Get weady!")
yay=Msgbox("SQUEEEEEEEEEEEEEEEEEEEEEE!! X3",vbOKOnly+16,"Should've said yes!")
End Select
End Select