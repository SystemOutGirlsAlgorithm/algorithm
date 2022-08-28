function solution(id_list, report, k) {
  const reportedBy = {};
  const reportedCount = {};
  const mailCount = {};

  const reportSet = new Set(report);

  id_list.forEach((v) => {
    reportedCount[v] = 0;
    mailCount[v] = 0;
    reportedBy[v] = [];
  });

  reportSet.forEach((v) => {
    const [reportID, reportedID] = v.split(" ");
    reportedCount[reportedID]++;
    reportedBy[reportedID].push(reportID);
  });

  for (let reportedID in reportedCount) {
    if (reportedCount[reportedID] >= k) {
      reportedBy[reportedID].forEach((v) => {
        mailCount[v]++;
      });
    }
  }

  return id_list.map((id) => mailCount[id]);
}
