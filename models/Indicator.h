/**
 *
 *  Indicator.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace sqlite3
{
class Counter;

class Indicator
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _id_counter;
        static const std::string _month;
        static const std::string _year;
        static const std::string _T1;
        static const std::string _T2;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = uint64_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Indicator(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Indicator(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Indicator(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Indicator() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const uint64_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const uint64_t &pId) noexcept;
    void setIdToNull() noexcept;

    /**  For column id_counter  */
    ///Get the value of the column id_counter, returns the default value if the column is null
    const uint64_t &getValueOfIdCounter() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getIdCounter() const noexcept;
    ///Set the value of the column id_counter
    void setIdCounter(const uint64_t &pIdCounter) noexcept;
    void setIdCounterToNull() noexcept;

    /**  For column month  */
    ///Get the value of the column month, returns the default value if the column is null
    const uint64_t &getValueOfMonth() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getMonth() const noexcept;
    ///Set the value of the column month
    void setMonth(const uint64_t &pMonth) noexcept;
    void setMonthToNull() noexcept;

    /**  For column year  */
    ///Get the value of the column year, returns the default value if the column is null
    const uint64_t &getValueOfYear() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getYear() const noexcept;
    ///Set the value of the column year
    void setYear(const uint64_t &pYear) noexcept;
    void setYearToNull() noexcept;

    /**  For column T1  */
    ///Get the value of the column T1, returns the default value if the column is null
    const uint64_t &getValueOfT1() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getT1() const noexcept;
    ///Set the value of the column T1
    void setT1(const uint64_t &pT1) noexcept;
    void setT1ToNull() noexcept;

    /**  For column T2  */
    ///Get the value of the column T2, returns the default value if the column is null
    const uint64_t &getValueOfT2() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getT2() const noexcept;
    ///Set the value of the column T2
    void setT2(const uint64_t &pT2) noexcept;
    void setT2ToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 6;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
    Counter getCounter(const drogon::orm::DbClientPtr &clientPtr) const;
    void getCounter(const drogon::orm::DbClientPtr &clientPtr,
                    const std::function<void(Counter)> &rcb,
                    const drogon::orm::ExceptionCallback &ecb) const;
  private:
    friend drogon::orm::Mapper<Indicator>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Indicator>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<uint64_t> id_;
    std::shared_ptr<uint64_t> idCounter_;
    std::shared_ptr<uint64_t> month_;
    std::shared_ptr<uint64_t> year_;
    std::shared_ptr<uint64_t> t1_;
    std::shared_ptr<uint64_t> t2_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[6]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
        if(dirtyFlag_[1])
        {
            sql += "id_counter,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "month,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "year,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "T1,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "T2,";
            ++parametersCount;
        }
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        if(dirtyFlag_[1])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace sqlite3
} // namespace drogon_model