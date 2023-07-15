var n,k: longint;
    OK:boolean;
//-------------------------------
procedure xuli;
var i,s,smax,x: longint;
begin
  readln(n,k);
  s := 0;  smax := -1;
  OK := false;
  for i:=1 to n do
   begin
      read(x);
      if (x mod k = 0) then
       begin
         if OK then inc(s)
         else
           begin
             OK := true;
             s := 1;
          end;
          if s > smax then smax := s;
        end
      else
        begin
         if OK then
           begin
             OK := false;
             if s > smax then smax := s;
             s := 0;
           end;
        end;
   end;
   writeln(smax);
end;
//------------------------------

begin
  assign(input,'daycon.inp'); reset(input);
  assign(output,'daycon.out'); rewrite(output);
    xuli;
  close(input); close(output);
end.
