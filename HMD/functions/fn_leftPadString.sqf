/*
* This function will pad a value (text or number) as necessary to the desired length.
*/
if (!hasInterface) exitWith {};

params [["_value", nil, ["", 0]], ["_length", 1, [0]], ["_padChar", " ", [""]]];

_text = str _value;

while { (count _text) < _length } do
{
	_text = [_padChar, _text] joinString "";
};

_text;
