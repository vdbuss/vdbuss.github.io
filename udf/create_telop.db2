create function telop (int,int) returns int
  external name 'tellib!telop'
  language C
  parameter style SQL
;
