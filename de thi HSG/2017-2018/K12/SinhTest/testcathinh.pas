const maxN = 1000;
var
    m,n,x,y,u,v: longint;

procedure taotest;
var i,j: longint;
begin
  randomize;
  m := random(maxN) + 1;
  n := random(maxN) + 1;
  writeln(m,#32,n);
  for i:=1 to m do
    begin
      for j:=1 to n do write(random(100),#32);
      writeln;
    end;
  x := random(m div 2)+1;
  u := x + 1 + random(m div 2);
  y := random(n div 2)+1;
  v := y + 1 + random(n div 2);

  write(x,#32,y,#32,u,#32,v);
end;
//------------------------------

begin
   assign(output,'cathinh14.inp'); rewrite(output);
    taotest;
   close(output);
end.
