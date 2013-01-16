#!/usr/bin/env ruby

require 'yaml'

class Convert
  attr_accessor :number_of_inputs, :number_of_outputs, :function, :specification, :pla_file
  def self.files
    Dir['*.pla'].map{|x| new x}
  end
  
  def initialize(file)
    self.specification = []
    self.pla_file = file

    File.open(file).each do |line|
      case line
      when /Function:\s*(.*)/i then self.function = $1.strip
      when /^\.i\s+(\d+)/ then self.number_of_inputs  = $1.to_i
      when /^\.o\s+(\d+)/ then self.number_of_outputs = $1.to_i
      when /^([\-\d]+\s+[\-\d]+)/  then self.specification << $1.sub(/\t/, ' ')
      end
    end
  end

  def complete?
    number_of_inputs == number_of_outputs
  end

  def to_xqs
    {
      'signature' =>  {'function'=> function},
      'inputs'   => {'radix'=> 2, 'variables'=> number_of_inputs},
      'outputs'   => {'radix'=> 2, 'variables'=> number_of_outputs},
      'specification' => specification 
    }.to_yaml
  end
end


Convert.files.select(&:complete?).each do |c|
  File.open("#{c.pla_file}.xqs", 'w') {|f| f.puts c.to_xqs}
end
