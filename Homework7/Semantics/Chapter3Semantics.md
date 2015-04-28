## Problem Set

### 21a.
    var E
    Stmts
    loop: if E == false goto exit
      Stmts
      goto loop
    exit:

### 22b.
    Mdo(do <sl> while (<be>), s) Δ =
      if Mbe(<be>, Msl(<sl>,s)) then
        Mdo(do <sl> while <be>, s)
      else
        Msl(<sl>, s)

### 24a.
    {b < 1}

### 25c.
    {y > 4/3}
