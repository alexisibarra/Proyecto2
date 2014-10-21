#!/usr/bin/env perl 
#===============================================================================
#
#         FILE: testFilesGenerator.pl
#
#        USAGE: ./testFilesGenerator.pl
#
#  DESCRIPTION:
#
#      OPTIONS: ---
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: YOUR NAME (),
# ORGANIZATION:
#      VERSION: 1.0
#      CREATED: 20/10/14 17:59:55
#     REVISION: ---
#===============================================================================

use strict;
use warnings;
use utf8;

foreach my $index ( 0 .. 3 ) {
    open( my $fh, '>:raw', "in" . 15**$index . ".bin" ) 
        or die "Unable to open: $!";
    foreach ( 0 .. 15**$index ) {
        print $fh pack('s<', int( rand(1000000) ));
    }
    close($fh);
}
