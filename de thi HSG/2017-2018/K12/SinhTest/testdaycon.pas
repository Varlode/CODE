const maxN = 10000; maxk = 10;
var n,k: longint;
//-------------------------------
procedure taotest;
var i,dau: longint;
begin
  randomize;
  n := random(maxN)+1;
  k := random(maxk)+2;
  writeln(n,#32,k);
  for i:=1 to n do
    begin
      dau := random(2);
      if dau=1 then dau := -1*dau else dau := 1;
      write(dau*random(9999),#32);
    end;
end;
//------------------------------
begin
  assign(output,'daycon12.inp'); rewrite(output);
    taotest;
  close(output);
end.
