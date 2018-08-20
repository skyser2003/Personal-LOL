using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace ApiSrcData
{
    public static class Helper
    {
        static List<Type> GetTypesInNamespace(Assembly assembly, string nameSpace)
        {
            return assembly.GetTypes()
                .Where(t => string.Equals(t.Namespace, nameSpace, StringComparison.Ordinal))
                .ToList();
        }

        public static Dictionary<Type, List<MemberInfo>> GetResultStructs()
        {
            var enumNames = Enum.GetNames(typeof(RiotApiType.ApiType));

            var results = enumNames
                .Select(enumName =>
                    $"ApiSrcData.ResultStruct.{enumName}, ApiSrcData, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null")
                .Select(Type.GetType)
                .Where(resultType => resultType != null)
                .ToList();

            var dict = new Dictionary<Type, List<MemberInfo>>();

            foreach (var result in results)
            {
                var members = new List<MemberInfo>();
                members.AddRange(result.GetMembers());

                dict.Add(result, members);
            }

            return dict;
        }

        public static List<Type> GetInternalStructs()
        {
            var apiSrcDataAssem = Assembly.GetAssembly(typeof(RiotApiType.ApiType));

            return GetTypesInNamespace(apiSrcDataAssem, "ApiSrcData.InternalStruct");
        }
    }
}