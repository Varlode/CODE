const maxN = 1000;


var a: array[1..MaxN,1..maxN] of longint;
    sum: array[0..maxN,0..maxN] of int64;
    m,n,x,y,u,v: longint;
    D_min: int64;

procedure chuanbi;
var i,j: longint;
begin
   for i:=1 to m do // tao mang sum
    for j:=1 to n do sum[i,j] := a[i,j] + sum[i-1,j] + sum[i,j-1] - sum[i-1,j-1];

end;
//-------------------------------
procedure xuli(x,y,u,v:longint);
var i,j,L,H,Mid: longint;  s,s1,s2: int64;
begin
  D_min := 2000000000000;

  L:=x; H:=u;
  s := (sum[H,v] - sum[H,y-1]) - (sum[x-1,v] - sum[x-1,y-1]);
  s1 := 0; s2 := 0;
  while (L<=H) do // cat hinh theo dong
    begin
      Mid := (L+H) div 2;
      s1 := (sum[Mid,v] - sum[Mid,y-1]) - (sum[x-1,v] - sum[x-1,y-1]);
      s2 := s - s1;
      if s1=s2 then begin D_min := s1 - s2; writeln(D_min); exit end;
      if abs(s1-s2) < D_min then D_min := abs(s1-s2);
      if s1<s2 then L := Mid +1
      else H := Mid -1;
    end;

  writeln(D_min);
end;

//----------------------------
procedure nhap;
var i,j: longint;
begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do read(a[i,j]);
      readln;
    end;

  chuanbi;
  readln(x,y,u,v);
  xuli(x,y,u,v);

end;
//------------------------------

begin
  assign(input,'cathinh.inp'); reset(input);  assign(output,'cathinh.out'); rewrite(output);
    nhap;
  close(input); close(output);
end.
