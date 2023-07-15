
uses  math;
const maxN = 2000;

var   A: array[1..maxN] of longint;
      F,Fleft,Fright: array[1..maxN] of longint; // bang phuong an
      n, Lmax: longint;

procedure nhap;
var i,j: longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
end;
//--------------------------------
procedure QHD;
var i,j: longint;
begin

// F[i] la do dai day wavio lon nhat
// Fleft[i] la do dai day wavio trai lon nhat
// Fright[i] la do dai day wavio phai lon nhat
// F[i] = 0 neu Fleft[i] =0 hoac  Fright[i] = 0 nguoc lai F[i] = Fleft[i] + Fright[i] + 1

// Co so QHD
   Fleft[1] := 0; // tai A1 khong co "nua day trai"
   Fright[n] := 0; // tai An khong co "nua day phai"
   F[1] := 0; F[n] := 0;

// Tinh Fleft[i]
   for i:=2 to n do
     for j:=i-1 downto 1 do
      if (a[j]<a[i]) and (Fleft[j]+1> Fleft[i]) then Fleft[i] := Fleft[j]+1;

// Tinh Fright[i]
   for i:=n-1 downto 1 do
     for j:=i+1 to n do
      if (a[j]<a[i]) and (Fright[j]+1> Fright[i]) then Fright[i] := Fright[j]+1;


// Tinh F[i] theo Fleft[i] va Fright[i], trong luc tinh F[i] ket hop tim F[i] lon nhat
   Lmax := 0;
   for i:=2 to n-1 do
    begin
      if (Fleft[i]=0) or (Fright[i]=0) then F[i] := 0
      else F[i] := Fleft[i] + Fright[i] +1;
      if F[i]>Lmax then Lmax := F[i];
    end;

  write(Lmax);
end;
//--------------------------------

BEGIN
  assign(input,'wavio.inp'); reset(input); assign(output,'wavio.out'); rewrite(output);
  nhap;
  QHD;
  close(input); close(output);

END.
