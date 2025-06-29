'x=MsgBox("Too bad! X3",vbOkOnly+16,"Nya!")
Dim shell
Dim i
Dim puffs
puffs=15
res=MsgBox("In order to pass, you must puff a balloon until it expwodes! x3",vbOkCancel+48,"Balloon Challenge")
Select Case res
Case vbOK
puf=MsgBox([puffs] & " Puffs left! (Click Yes to puff)",vbYesNo+64,"Puffing Time!")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Puffing Time!")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Puffing Time!")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Puffing Time!")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Puffing Time!")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"It's getting big...")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"It's getting big...")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"It's getting big...")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"It's getting big...")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"It's getting big...")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Almost!~")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Almost!~")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Almost!~")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puffs left!",vbYesNo+64,"Almost!~")
Select Case puf
Case vbYes
puffs=puffs-1
puf=MsgBox([puffs] & " Puff left! x3",vbYesNo+64,"Crrreaakk...")
Select Case puf
Case vbYes
puffs=puffs-1
fin=MsgBox("BAAANGG! You win! x3",vbOKOnly+16,"BOOM!")
Case vbNo
x=MsgBox("You were so cwose! >~<",vbOkOnly+16,"NOOOOOO!")
End Select
Case vbNo
x=MsgBox("You were two puffs away! >~<",vbOkOnly+16,"NOOOOOO!")
End Select
Case vbNo
x=MsgBox("Don't give up! >~<",vbOkOnly+16,"NOOOOOO!")
End Select
Case vbNo
x=MsgBox("Get better wungs! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("Hehe! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("Need a rest? Too bad! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("You failed! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("You were halfway there! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("I won! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("Tired alweady? >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("Better wuck next time! >:3",vbOkOnly+16,"Nya!")
End Select
Case vbNo
x=MsgBox("Is that really it? -~-",vbOkOnly+16,"C'mon!")
End Select
Case vbNo
x=MsgBox("Try hawder! -~-",vbOkOnly+16,"C'mon!")
End Select
Case vbNo
x=MsgBox("That's all? -~-",vbOkOnly+16,"C'mon!")
End Select
Case vbNo
x=MsgBox("Really? -~-",vbOkOnly+16,"C'mon!")
End Select
Case vbCancel
x=MsgBox("You cancelled the chawwenge? YOU MUST PAY! >:3",vbOkOnly+16,"Nya!")
End Select