// Ma bai NKCITY

Const
      maxN = 1000;  maxM = 10000;

type
       banghi = record
                  u, v, c: longint;
                  danhdau: Boolean;
                end;
var
   canh: array[1..maxM] of banghi;
   Lab: array[1..maxN] of longint;

   n, m: longint;

//-------------------------------
procedure nhap;
var  i: longint;
begin
      ReadLn(n, m);
      for i := 1 to m do
      	with canh[i] do begin ReadLn(u, v, c); canh[i].danhdau := false; end;

      for i := 1 to n do Lab[i] := -1;
end;
//-------------------------------
function GetRoot(v:longint): longint;
begin
   while Lab[v] > 0 do v := Lab[v];
   GetRoot := v;
end;
//-------------------------------
procedure Hopnhat(r1, r2: Longint);
var x: Longint;
begin
x := Lab[r1] + Lab[r2];
if Lab[r1] > Lab[r2] then    // neu cay goc r1 it nut hon
    begin  Lab[r1] := r2; Lab[r2] := x; end  // hop nhat cay goc r1 vao cay goc r2
else
    begin  Lab[r1] := x; Lab[r2] := r1; end; // hop nhat cay goc r2 vao cay goc r1
end;
//-------------------------------
procedure Doicho(var a,b:banghi);
var tam : banghi;
begin
        tam:=a;
	a:=b;
	b:=tam;
end;
//---------------------------------------------
Procedure QuickSort(L,H:longint);
Var i,j,chot: longint;
Begin
  If L>=H then Exit;
  Chot := canh[(L+H) div 2].c;
  i := L;
  j := H;
  Repeat
    While canh[i].c < Chot do inc(i);
    While canh[j].c > Chot do dec(j);
    If i<=j then
      Begin
        If i<j then DoiCho(canh[i],canh[j]);
        Inc(i); Dec(j);
      End;
  Until i>j;

  if L<j then QuickSort(L,j);
  if i<H then QuickSort(i,H);
End;
//---------------------------------------------
procedure Kruskal; // thu tuc dung cƒy
var  i, r1, r2, Dem, canhmax: Longint;
begin
  Quicksort(1,m);
  Dem := 0;
  canhmax := -1;

  for i := 1 to m do
    begin
        r1 := GetRoot(canh[i].u); r2 := GetRoot(canh[i].v);
        if r1 <> r2 then
           begin
             canh[i].danhdau := True; Inc(Dem);
             if canhmax < canh[i].c then canhmax := canh[i].c;
             if Dem = n - 1 then  break;
             Hopnhat(r1, r2);
           end;
    end;

  write(canhmax);
end;
//-------------------------------
begin
 Assign(Input, 'giaothong.inp'); Reset(Input);    Assign(Output, 'giaothong.out'); Rewrite(Output);
    nhap;
    Kruskal;
 Close(Input); Close(Output);
end.





