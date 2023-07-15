const
      fo = 'windows13.inp';
      MaxN = 100; MaxM = 100;

var
     N,M,L,tt,x,y,u,v: Longint;
     free: array[1..MaxM] of boolean;

procedure taotest;
var i: Longint;
begin
  randomize;
  N := random(MaxN)+1;
  M := random(MaxM)+1;
  L := random(M)+1;
  writeln(N,#32,M,#32,L);
  For i:=1 to M do
     begin
       x := random(N div 2);
       u := x + random(N div 2)+1;
       y := random(N div 2);
       v := y + random(N div 2)+1;
       writeln(x,#32,y,#32,u,#32,v);
     end;

  fillchar(free,sizeof(free),true);

  For i:=1 to M do
    begin
      repeat
        tt := random(M)+1;
      until free[tt] = true;
      write(tt,#32);
      free[tt] := false;
    end;

end;
//-------------------------------------
BEGIN

    assign(Output,fo); rewrite(Output);

       taotest;

    Close(Output);
END.
