Dim shell
Set shell = CreateObject("WScript.Shell")
do
x=MsgBox("Cut off a head. Two more will take its place",vbOkOnly+0,"")
shell.Run ".\hydra.vbs"
loop