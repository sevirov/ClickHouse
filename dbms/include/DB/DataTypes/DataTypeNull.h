#pragma once

#include <DB/DataTypes/IDataType.h>

namespace DB
{

class DataTypeNull : public IDataType
{
public:
	using FieldType = Null;

public:
	DataTypeNull() = default;
	std::string getName() const override;
	bool isNull() const override;
	bool isNumeric() const override;
	bool behavesAsNumber() const override;
	DataTypePtr clone() const override;
	void serializeBinary(const IColumn & column, WriteBuffer & ostr, size_t offset = 0, size_t limit = 0) const override;
	void deserializeBinary(IColumn & column, ReadBuffer & istr, size_t limit, double avg_value_size_hint) const override;
	void serializeBinary(const Field & field, WriteBuffer & ostr) const override;
	void deserializeBinary(Field & field, ReadBuffer & istr) const override;
	void serializeBinary(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	void deserializeBinary(IColumn & column, ReadBuffer & istr) const override;
	void serializeTextEscaped(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	void deserializeTextEscaped(IColumn & column, ReadBuffer & istr) const override;
	void serializeTextQuoted(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	void deserializeTextQuoted(IColumn & column, ReadBuffer & istr) const override;
	void serializeTextCSV(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	void deserializeTextCSV(IColumn & column, ReadBuffer & istr, const char delimiter) const override;
	void serializeTextJSON(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	void deserializeTextJSON(IColumn & column, ReadBuffer & istr) const override;
	void serializeText(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
	ColumnPtr createColumn() const override;
	ColumnPtr createConstColumn(size_t size, const Field & field) const override;
	Field getDefault() const override;
	size_t getSizeOfField() const override;
};

}
