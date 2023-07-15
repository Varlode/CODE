const maxN = 1000000;

var
    a,b: ansistring;

procedure taotest;
var i,x: longint;
begin
  randomize;
  a := '';
  for i:=1 to maxn do
    begin
       x := random(26);
       a := a + chr(x+97);
    end;
  {  for i:=1 to 5 do
    begin
       x := random(26);
       b := b + chr(x+97);
    end;}
  writeln(a);
//  writeln(b);
end;
//------------------------------------------
begin
  assign(output,'xaucon14.inp'); rewrite(output);
    taotest;
  close(output);
end.

