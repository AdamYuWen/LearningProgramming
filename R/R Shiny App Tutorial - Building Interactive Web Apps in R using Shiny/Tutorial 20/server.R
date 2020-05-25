library(shiny)

# Must have the session argument.
shinyServer(function(session, input, output) {
  observeEvent(
    # After changing the Year, update the Month input.
    input$Year,
    # Must have the session input.
    updateSelectInput(session = session,
                      inputId = "Month",
                      label = "Month",
                      choices = data$Month[data$Year == input$Year])
  )

  observeEvent(
    input$Month,
    updateSelectInput(session = session,
                      inputId = "Name",
                      label = "Name",
                      choices = data$Name[data$Year == input$Year &
                                          data$Month == input$Month])
  )

  # data was stored in global.R.
  output$dataset <- renderTable(data)
})
