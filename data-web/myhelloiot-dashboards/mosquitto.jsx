{/* Mosquitto SYS topics example. */}

<DashboardPage title="Mosquitto SYS topics">
  <h3 className="myhDashboardPage-all">Broker</h3>
  <InputCard
    title="Version"
    subtopic="$SYS/broker/version" />
  <InputCard
    title="Uptime"
    subtopic="$SYS/broker/uptime" />
  <InputCard
    title="Total clients"
    subtopic="$SYS/broker/clients/total"
    format={NumberValueFormat()} />
  <InputCard
    title="Connected clients"
    subtopic="$SYS/broker/clients/connected" format={NumberValueFormat()} />
  <h3 className="myhDashboardPage-all">Load</h3>
  <InputCard
    title="Received"
    subtopic="$SYS/broker/bytes/received"
    format={NumberValueFormat()} />
  <InputCard
    title="Received in 5 min."
    subtopic="$SYS/broker/load/bytes/received/5min"
    format={NumberValueFormat()} />
  <InputCard
    title="Sent"
    subtopic="$SYS/broker/bytes/sent"
    format={NumberValueFormat()} />
  <InputCard
    title="Sent in  5 min."
    subtopic="$SYS/broker/load/bytes/sent/5min"
    format={NumberValueFormat()} />
  <h3 className="myhDashboardPage-all">Messages</h3>
  <InputCard
    title="Received"
    subtopic="$SYS/broker/messages/received"
    format={NumberValueFormat()} />
  <InputCard
    title="Sent"
    subtopic="$SYS/broker/messages/sent"
    format={NumberValueFormat()} />
  <InputCard
    title="Dropped"
    subtopic="$SYS/broker/messages/publish/dropped"
    format={NumberValueFormat()} />
  <InputCard
    title="Stored"
    subtopic="$SYS/broker/messages/stored"
    format={NumberValueFormat()} />
</DashboardPage>
