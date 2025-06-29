Dim x
Dim value
x=Msgbox("",vbYesNo+0,"Yes or no")
Select Case x
Case vbYes
value = 0
Case vbNo
value = 1
End Select
If value = 0 Then
y=Msgbox("Yes has been chosen",vbOKOnly+0,"Result")
ElseIf value = 1 Then
n=Msgbox("No has been chosen",vbOKOnly+0,"Result")
End If